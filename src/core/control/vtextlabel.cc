#include "../../../include/core/control/vtextlabel.h"

VLIB_BEGIN_NAMESPACE

namespace Core {

void VTextLabel::SetTheme(Core::VTextLabelTheme* NewTheme) {
    Theme = NewTheme;
}
Core::VTextLabelTheme* VTextLabel::GetTheme() {
    return Theme;
}

VTextLabel::VTextLabel(Core::VUIObject *Parent) : VAbstractButton(Parent) {
    Theme = new VTextLabelTheme(*(static_cast<VTextLabelTheme*>(GetTargetTheme(VUIThemeType::VTextLabel))));

    Interpolator = new VAnimationInterpolator(0.1, Theme->LocalTheme.AnimationInterpolatorType);
}
VTextLabel::VTextLabel(int Width, int Height, VUIObject* Parent) : VAbstractButton(Parent) {
    Theme = new VTextLabelTheme(*(static_cast<VTextLabelTheme*>(GetTargetTheme(VUIThemeType::VTextLabel))));

    Resize(Width, Height);

    Interpolator = new VAnimationInterpolator(0.1, Theme->LocalTheme.AnimationInterpolatorType);
}
VTextLabel::VTextLabel(int Width, int Height, const std::wstring &PlaneText, Core::VUIObject *Parent) : VAbstractButton(Parent) {
    Theme = new VTextLabelTheme(*(static_cast<VTextLabelTheme*>(GetTargetTheme(VUIThemeType::VTextLabel))));

    Resize(Width, Height);

    Theme->PlaneText = PlaneText;

    Interpolator = new VAnimationInterpolator(0.1, Theme->LocalTheme.AnimationInterpolatorType);
}
VTextLabel::~VTextLabel() {
    delete Theme;
    delete Interpolator;
}

void VTextLabel::LeftClickedDown() {
    InAnimation = true;

    OldTheme = Theme->LocalTheme;
    TargetTheme = Theme->ActiveTheme;

    Interpolator->Reset();
    AnimationFrameTimer.Start(0);

    Update();
}
void VTextLabel::LeftClickedUp() {
    InAnimation = true;

    OldTheme = Theme->LocalTheme;
    TargetTheme = Theme->OnHoverTheme;

    Interpolator->Reset();
    AnimationFrameTimer.Start(0);

    Update();
}
void VTextLabel::GotMouseFocus() {
    InAnimation = true;

    OldTheme = Theme->LocalTheme;
    TargetTheme = Theme->OnHoverTheme;

    Interpolator->Reset();
    AnimationFrameTimer.Start(0);

    Update();
}
void VTextLabel::LosedMouseFocus() {
    InAnimation = true;

    OldTheme = Theme->LocalTheme;
    TargetTheme = Theme->StaticTheme;

    Interpolator->Reset();
    AnimationFrameTimer.Start(0);

    Update();
}
void VTextLabel::CheckFrame() {
    if (!Interpolator->IsEnd() && InAnimation) {
        if (AnimationFrameTimer.End()) {
            AnimationFrameTimer.Start(16);

            auto AnimationCurvature = Interpolator->GetOneFrame();

            Theme->LocalTheme.BorderThickness = TargetTheme.BorderThickness +
                                                (OldTheme.BorderThickness - TargetTheme.BorderThickness) *
                                                (1.f - AnimationCurvature);

            Theme->LocalTheme.TextColor = VColorInterpolator::GetTheColorByPercent(OldTheme.TextColor,
                                                                                   TargetTheme.TextColor,
                                                                                   AnimationCurvature);
            Theme->LocalTheme.BackgroundColor = VColorInterpolator::GetTheColorByPercent(OldTheme.BackgroundColor,
                                                                                         TargetTheme.BackgroundColor,
                                                                                         AnimationCurvature);
            Theme->LocalTheme.BorderColor = VColorInterpolator::GetTheColorByPercent(OldTheme.BorderColor,
                                                                                     TargetTheme.BorderColor,
                                                                                     AnimationCurvature);

            Theme->LocalTheme.Radius.X = TargetTheme.Radius.X +
                                         (OldTheme.Radius.X - TargetTheme.Radius.X) * (1.f - AnimationCurvature);
            Theme->LocalTheme.Radius.Y = TargetTheme.Radius.Y +
                                         (OldTheme.Radius.Y - TargetTheme.Radius.Y) * (1.f - AnimationCurvature);

            Update();
        }
    } else if (InAnimation) {
        InAnimation = false;
    }
}
void VTextLabel::OnPaint(VCanvasPainter* Painter) {
    Painter->BeginDraw();

    VSolidBrush BackgroundBrush(CallWidgetGetDCRenderTarget()->GetDirectXRenderTarget(),
                                Theme->LocalTheme.BackgroundColor);
    VPenBrush   PenBrush(CallWidgetGetDCRenderTarget()->GetDirectXRenderTarget(),
                         Theme->LocalTheme.BorderColor, Theme->LocalTheme.BorderThickness);
    VSolidBrush TextBrush(CallWidgetGetDCRenderTarget()->GetDirectXRenderTarget(),
                          Theme->LocalTheme.TextColor);

    Painter->FillRoundedRectangle(
            {
                    static_cast<int>(Theme->LocalTheme.BorderThickness),
                    static_cast<int>(Theme->LocalTheme.BorderThickness),
                    GetWidth(), GetHeight()
            },
            Theme->LocalTheme.Radius, &PenBrush, &BackgroundBrush);
    Painter->DrawString(Theme->PlaneText,
                        {
                                static_cast<int>(Theme->LocalTheme.BorderThickness),
                                static_cast<int>(Theme->LocalTheme.BorderThickness),
                                GetWidth(), GetHeight()
                        }, Theme->LabelFont, &TextBrush);

    Painter->EndDraw();
}
void VTextLabel::SetPlaneText(const std::wstring& PlaneText) {
    Theme->PlaneText = PlaneText;

    Update();
}
void VTextLabel::SetTextColor(const VColor& TextColor) {
    Theme->StaticTheme.TextColor = TextColor;
    Theme->OnHoverTheme.TextColor = TextColor;
    Theme->ActiveTheme.TextColor = TextColor;
    Theme->LocalTheme.TextColor = TextColor;

    Update();
}
void VTextLabel::SetBackgroundColor(const VColor& BackgroundColor) {
    Theme->StaticTheme.BackgroundColor = BackgroundColor;
    Theme->OnHoverTheme.BackgroundColor = BackgroundColor;
    Theme->ActiveTheme.BackgroundColor = BackgroundColor;
    Theme->LocalTheme.BackgroundColor = BackgroundColor;

    Update();
}
void VTextLabel::SetRadius(const VPoint& Radius) {
    Theme->StaticTheme.Radius = Radius;
    Theme->OnHoverTheme.Radius = Radius;
    Theme->ActiveTheme.Radius = Radius;
    Theme->LocalTheme.Radius = Radius;

    Update();
}
void VTextLabel::SetTextSize(const int& TextSize) {
    auto FontStretch= Theme->LabelFont->GetFontStretchStyle();
    auto FamilyName  = Theme->LabelFont->GetFamilyName();
    auto TextFontStyle = Theme->LabelFont->GetTextFontStyle();
    auto TextWeightStyle = Theme->LabelFont->GetTextWeightStyle();

    delete Theme->LabelFont;

    LCID    LocaleID = GetThreadLocale();
    wchar_t LocaleName[LOCALE_NAME_MAX_LENGTH];
    if(!LCIDToLocaleName(LocaleID, LocaleName, LOCALE_NAME_MAX_LENGTH, 0)){
        VLIB_REPORT_ERROR(L"Failed to get the system locale");
    }

    Theme->LabelFont = new VFont(FamilyName, TextWeightStyle, TextFontStyle, FontStretch,
                                 static_cast<float>(TextSize), LocaleName);

    Update();
}
VRect VTextLabel::GetRegion() {
    VRect Rect = VUIObject::GetRegion();

    Rect.Extended(
            static_cast<int>(Theme->LocalTheme.BorderThickness), static_cast<int>(Theme->LocalTheme.BorderThickness),
            static_cast<int>(Theme->LocalTheme.BorderThickness), static_cast<int>(Theme->LocalTheme.BorderThickness));
    return Rect;
}
void VTextLabel::SetLineAlignment(const Core::VFontAlignment& Alignment) {
    Theme->LabelFont->SetLineAlignment(Alignment);

    Update();
}
void VTextLabel::SetParagraphAlignment(const Core::VFontParagraphAlignment& Alignment) {
    Theme->LabelFont->SetParagraphAlignment(Alignment);

    Update();
}

void VTextLabel::SetAutoSize(const bool &Status) {
    AutoSize = Status;
    if (Status) {
        ResizeByText();
    }

    Update();
}

std::wstring VTextLabel::GetPlaneText() const {
    return Theme->PlaneText;
}
bool         VTextLabel::GetAutoSizeStatus() const {
    return AutoSize;
}

void VTextLabel::ResizeByText(const std::wstring &Text) {
    IDWriteTextLayout* TextLayout;

    VLIB_CHECK_REPORT(VDirectXWriteFactory.GetInstance()->CreateTextLayout(
            Text.c_str(), Text.size(),
            Theme->LabelFont->GetDXObject(),
            INT_MAX,
            INT_MAX,
            &TextLayout
    ), L"Failed to create TextLayout object!");

    DWRITE_TEXT_METRICS TextMetrics;
    TextLayout->GetMetrics(&TextMetrics);

    Resize(TextMetrics.width + TextMetrics.left, TextMetrics.height + TextMetrics.top);

    VDXObjectSafeFree(&TextLayout);
}
void VTextLabel::ResizeByText() {
    IDWriteTextLayout* TextLayout;

    VLIB_CHECK_REPORT(VDirectXWriteFactory.GetInstance()->CreateTextLayout(
            Theme->PlaneText.c_str(), Theme->PlaneText.size(),
            Theme->LabelFont->GetDXObject(),
            0.f,
            0.f,
            &TextLayout
    ), L"Failed to create TextLayout object!");

    DWRITE_OVERHANG_METRICS TextMetrics;
    TextLayout->GetOverhangMetrics(&TextMetrics);

    Resize(ceil(TextMetrics.bottom), (Theme->LabelFont->GetDXObject()->GetFontWeight()));

    VDXObjectSafeFree(&TextLayout);
}

}

VLIB_END_NAMESPACE