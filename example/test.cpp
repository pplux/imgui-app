#include "../imgui.h" // > imgui headers (+imgui_app definitions)

char buf[128];
float f;

void frame() {
    ImGui::Text("Hello, world %d", 123);
    if (ImGui::Button("Button")) {
        buf[0] = 0;
        f = 1.0f;
    }
    ImGui::InputText("string", buf, IM_ARRAYSIZE(buf));
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    // 
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
