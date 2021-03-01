// Amalgamated version of :
//     - imgui 
//     - sokol_[app, gfx, time, imgui, ...] for multiplatform rendering
//
// ----------------------------------------------------------------------------

// Starts the graphical context, and runs the UI. This function will not return 
// until the app finishes.
void imgui_app(
    void (*frame_func)(),
    const char *window_title = "IMGUI APP",
    int width = 800,
    int height = 600,
    int ImGuiConfigFlags = 0
    );


typedef void* ImTextureID;
ImTextureID imgui_app_loadImageRGBA8(const void *data, int width, int height);
void imgui_app_destroyImage(ImTextureID id);

// Allows to configure sokol manually/
//    - Remember to call previous event function if you decide to verride the event callback
extern "C" {
    struct sapp_desc;
}
void imgui_app(void (*frame_func)(), void (*config_sokol)(sapp_desc *), int ImGuiConfigFlags = 0);



//
// ----------------------------------------------------------------------------
