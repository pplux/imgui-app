// imgui_app by PpluX (Jose L. Hidalgo) 2021

static struct {
    uint64_t laptime;
    sg_pass_action pass_action;
    void (*frame_fn)();
} state = {};

static void init(void) {
    sg_desc desc = {};
    desc.context = sapp_sgcontext();
    sg_setup(&desc);
    stm_setup();
    simgui_desc_t desc_imgui = {};
    simgui_setup(&desc_imgui);

    state.pass_action.colors[0].action = SG_ACTION_CLEAR;
    state.pass_action.colors[0].val[0] = 0.12f;
    state.pass_action.colors[0].val[1] = 0.12f;
    state.pass_action.colors[0].val[2] = 0.12f;
    state.pass_action.colors[0].val[3] = 1.0f;
}

static void frame(void) {
    const int width = sapp_width();
    const int height = sapp_height();
    const double delta_time = stm_sec(stm_round_to_common_refresh_rate(stm_laptime(&state.laptime)));
    simgui_new_frame(width, height, delta_time);

    state.frame_fn();

    sg_begin_default_pass(&state.pass_action, width, height);
    simgui_render();
    sg_end_pass();
    sg_commit();
}

static void cleanup(void) {
    simgui_shutdown();
    sg_shutdown();
}

static void event(const sapp_event* ev) {
    simgui_handle_event(ev);
}

void imgui_app(void (*frame_func)(), const char *window_title, int width, int height) {
    state.frame_fn = frame_func;
    sapp_desc desc = {};
    desc.init_cb = init;
    desc.frame_cb = frame;
    desc.cleanup_cb = cleanup;
    desc.event_cb = event;
    desc.window_title = window_title;
    desc.width = width;
    desc.height = height;
    sapp_run(&desc);
}
