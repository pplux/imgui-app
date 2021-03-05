#include <cstdlib>
#include "../imgui.h" // > imgui headers (+imgui_app definitions)

char buf[128];
float f;
ImTextureID tex = 0;

void frame() {
    ImGui::Text("Hello, world %d", 123);
    if (ImGui::Button("Button")) {
        buf[0] = 0;
        f = 1.0f;
    }
    ImGui::InputText("string", buf, IM_ARRAYSIZE(buf));
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    if (tex == 0) {
        unsigned char buffer[32*32*4];
        for(int i = 0; i < 32*32; ++i) {
            buffer[i*4+0] = std::rand()%255;
            buffer[i*4+1] = std::rand()%255;
            buffer[i*4+2] = std::rand()%255;
            buffer[i*4+3] = 255;
        }
        tex = imgui_app_loadImageRGBA8(buffer, 32, 32);
    }
    ImGui::Image(tex, {256, 256});
    ImGui::ShowDemoWindow();
}


int main(int, char **) {
    // do any initialization 
    buf[0] = 0;
    f = 0.0f;
    // when ready start the UI (this will not return until the app finishes)
    int imguiConfigFlags = 0;
    // imguiConfigFlags = ImGuiConfigFlags_DockingEnable // (if you use the docking branch)
    imgui_app(frame, "IMGUI_APP", 800, 600, imguiConfigFlags);    
    return 0;
}
