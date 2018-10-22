#pragma once

#include <mbgl/renderer/renderer_backend.hpp>

#include <memory>
#include <functional>

#include "omnisci_log_callback.hpp"

namespace mbgl {

class HeadlessBackend : public RendererBackend {
public:
    HeadlessBackend(Size = { 256, 256 });
    ~HeadlessBackend() override;

    void bind() override;
    Size getFramebufferSize() const override;
    void updateAssumedState() override;

    void setSize(Size);
    PremultipliedImage readStillImage();

    class Impl {
    public:
        virtual ~Impl() = default;
        virtual gl::ProcAddress getExtensionFunctionPointer(const char*) = 0;
        virtual void activateContext() = 0;
        virtual void deactivateContext() {}
    };

    void setOmniSciLogCallback(OmniSciLogCallback omnisci_log_callback) { _omnisci_log_callback = omnisci_log_callback; }

private:
    // Implementation specific functions
    gl::ProcAddress getExtensionFunctionPointer(const char*) override;

    void activate() override;
    void deactivate() override;

    void createImpl(OmniSciLogCallback);

private:
    std::unique_ptr<Impl> impl;

    Size size;
    float pixelRatio;
    bool active = false;

    class View;
    std::unique_ptr<View> view;

    OmniSciLogCallback _omnisci_log_callback = nullptr;
};

} // namespace mbgl
