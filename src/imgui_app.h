// Amalgamated version of :
//     - imgui 
//     - sokol_[app, gfx, time, imgui, ...] for multiplatform rendering
//
// ----------------------------------------------------------------------------

#include <functional>

// Starts the graphical context, and runs the UI. This function will not return 
// until the app finishes.
void imgui_app(
    std::function<void()> &&frame_func,
    const char *window_title = "IMGUI APP",
    int width = 800,
    int height = 600,
    int ImGuiConfigFlags = 0
    );

// Called by imgui-app unless you override the event callback
void imgui_app_event(const sapp_event* ev);


typedef void* ImTextureID;
ImTextureID imgui_app_loadImageRGBA8(const void *data, int width, int height);
void imgui_app_destroyImage(ImTextureID id);

// Allows to configure sokol manually/
//    - Remember to call previous event function if you decide to override the event callback
//    - The passed function must return the Imgui config flags (default 0)
extern "C" {
    struct sapp_desc;
}
void imgui_app(std::function<void()> &&frame_func, void (*config_sokol)(sapp_desc *), int ImGuiConfigFlags = 0);

//
// ----------------------------------------------------------------------------
