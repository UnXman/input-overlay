#include "DialogElementSettings.hpp"
#include <utility>
#include "../Config.hpp"

void DialogElementSettings::init()
{
    Dialog::init();
    int8_t id = 1;

    /* Labels */
    add(new Label(id++, 8, 35, LANG_LABEL_WIDTH, this));
    add(new Label(id++, (m_dimensions.w / 2) + 4, 35, LANG_LABEL_HEIGHT, this));
    add(new Label(id++, 8, 65, LANG_LABEL_X, this));
    add(new Label(id++, (m_dimensions.w / 2) + 4, 65, LANG_LABEL_Y, this));
    add(new Label(id++, 8, 95, LANG_LABEL_U, this));
    add(new Label(id++, (m_dimensions.w / 2) + 4, 95, LANG_LABEL_V, this));
    add(new Label(id++, 8, 125, LANG_LABEL_ELEMENT_ID, this));
    add(new Label(id++, 8, 170, LANG_LABEL_KEY_CODE, this));
    add(new Label(id++, (m_dimensions.w / 2) + 8, 170, LANG_LABEL_Z_LEVEL, this));

    /* Text boxes */
    m_element_width = new Textbox(id++, 55, 32, (m_dimensions.w / 2) - 63, 20, "0", this);
    m_element_height = new Textbox(id++, (m_dimensions.w / 2) + 55, 32, (m_dimensions.w / 2) - 63, 20, "0", this);

    m_element_x = new Textbox(id++, 55, 62, (m_dimensions.w / 2) - 63, 20, "0", this);
    m_element_y = new Textbox(id++, (m_dimensions.w / 2) + 55, 62, (m_dimensions.w / 2) - 63, 20, "0", this);

    m_element_u = new Textbox(id++, 55, 92, (m_dimensions.w / 2) - 63, 20, "0", this);
    m_element_v = new Textbox(id++, (m_dimensions.w / 2) + 55, 92, (m_dimensions.w / 2) - 63, 20, "0", this);

    m_element_width->set_flags(TEXTBOX_NUMERIC);
    m_element_height->set_flags(TEXTBOX_NUMERIC);
    m_element_x->set_flags(TEXTBOX_NUMERIC);
    m_element_y->set_flags(TEXTBOX_NUMERIC);
    m_element_u->set_flags(TEXTBOX_NUMERIC);
    m_element_v->set_flags(TEXTBOX_NUMERIC);

    m_element_width->set_cutoff(20);
    m_element_height->set_cutoff(20);
    m_element_x->set_cutoff(20);
    m_element_y->set_cutoff(20);
    m_element_u->set_cutoff(20);
    m_element_v->set_cutoff(20);

    add(m_element_width);
    add(m_element_height);
    add(m_element_x);
    add(m_element_y);
    add(m_element_u);
    add(m_element_v);

    add(m_element_id = new Textbox(id++, 8, 145, m_dimensions.w - 16, 20, "", this));
    add(m_element_vc = new Textbox(id++, 8, 190, m_dimensions.w / 2 - 16, 20, "", this));

    add(m_element_z_level = new Textbox(id++, m_dimensions.w / 2 + 8, 190, m_dimensions.w / 2 - 16, 20, "0", this));

    m_element_id->set_flags(TEXTBOX_NO_SPACE | TEXTBOX_ALPHA_NUMERIC);
    m_element_vc->set_flags(TEXTBOX_HEX | TEXTBOX_NO_SPACE);
    m_element_z_level->set_flags(TEXTBOX_NUMERIC);

    /* Controls */
    add(new Button(ACTION_NEW_ELEMENT, 8, m_dimensions.h - 182, m_dimensions.w - 16, LANG_BUTTON_ADD_ELEMENT, this));
    add(new Button(ACTION_DEL_ELEMENT, 8, m_dimensions.h - 154, m_dimensions.w - 16, LANG_BUTTON_DELETE_ELEMENT, this));
    add(new Button(ACTION_MOD_ELEMENT, 8, m_dimensions.h - 126, m_dimensions.w - 16, LANG_BUTTON_MODIFY_ELEMENT, this));
    add(new Button(ACTION_SAVE_CONFIG, 8, m_dimensions.h - 98, m_dimensions.w - 16, LANG_BUTTON_SAVE_CONFIG, this));
    add(new Button(ACTION_HELP_BUTTON, 8, m_dimensions.h - 70, m_dimensions.w - 16, LANG_BUTTON_HELP, this));
    add(new Button(ACTION_OK, 8, m_dimensions.h - 32, LANG_BUTTON_OK, this));

    set_flags(DIALOG_DRAGGABLE | DIALOG_TEXTINPUT);
}

void DialogElementSettings::action_performed(int8_t action_id)
{
    switch (action_id)
    {
    case ACTION_OK:
        if (m_tool->get_selected())
            m_tool->get_selected()->update_settings(this);
        break;
    case ACTION_DEL_ELEMENT:
        if (m_tool->get_selected() && m_tool->get_selected_id() >= 0)
        {
            m_tool->delete_element(m_tool->get_selected_id());
        }
        break;
    case ACTION_MOD_ELEMENT:
        m_tool->queue_dialog_open(DialogID::MOD_ELEMENT);
        break;
    case ACTION_HELP_BUTTON:
        m_tool->queue_dialog_open(DialogID::HELP);
        break;
    case ACTION_NEW_ELEMENT:
        m_tool->queue_dialog_open(DialogID::SELECECT_TYPE);
        break;
    case ACTION_SAVE_CONFIG:
        m_tool->action_performed(TOOL_ACTION_SAVE_CONFIG);
        break;
    }
}

void DialogElementSettings::set_wh(int w, int h)
{
    if (w >= 0)
    {
        m_element_width->set_text(std::to_string(w));
    }

    if (h >= 0)
    {
        m_element_height->set_text(std::to_string(h));
    }
}

void DialogElementSettings::set_xy(int x, int y)
{
    if (x >= 0)
    {
        m_element_x->set_text(std::to_string(x));
    }

    if (y >= 0)
    {
        m_element_y->set_text(std::to_string(y));
    }
}

void DialogElementSettings::set_uv(int u, int v)
{
    if (u >= 0)
    {
        m_element_u->set_text(std::to_string(u));
    }

    if (v >= 0)
    {
        m_element_v->set_text(std::to_string(v));
    }
}

void DialogElementSettings::set_id(std::string id)
{
    m_element_id->set_text(std::move(id));
}

void DialogElementSettings::set_vc(uint16_t vc)
{
    m_element_vc->set_hex_int(vc);
}

void DialogElementSettings::set_z_level(uint8_t z)
{
    m_element_z_level->set_text(std::to_string(z));
}

void DialogElementSettings::select_element(Element * e)
{
    if (e)
    {
        set_id(*e->get_id());
        set_uv(e->get_u(), e->get_v());
        set_xy(e->get_x(), e->get_y());
        set_wh(e->get_w(), e->get_h());
        set_vc(e->get_vc());
        set_z_level(e->get_z_level());
    }
}
