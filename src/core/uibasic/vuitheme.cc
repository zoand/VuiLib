#include "../../../include/core/uibasic/vuitheme.h"

VLIB_BEGIN_NAMESPACE

namespace Core
{

VLabelStatusTheme::VLabelStatusTheme(const VLabelStatusTheme &Theme)
{
	BackgroundColor			  = Theme.BackgroundColor;
	BorderColor				  = Theme.BorderColor;
	TextColor				  = Theme.TextColor;
	BorderThickness			  = Theme.BorderThickness;
	Radius					  = Theme.Radius;
	AnimationInterpolatorType = Theme.AnimationInterpolatorType;
}
VLabelCommonTheme::VLabelCommonTheme(const VLabelCommonTheme &LabelObject)
{
	StaticTheme	 = LabelObject.StaticTheme;
	OnHoverTheme = LabelObject.OnHoverTheme;
	ActiveTheme	 = LabelObject.ActiveTheme;
}
VLabelCommonTheme::VLabelCommonTheme()
{
	LCID	LocaleID = GetThreadLocale();
	wchar_t LocaleName[LOCALE_NAME_MAX_LENGTH];
	if (!LCIDToLocaleName(LocaleID, LocaleName, LOCALE_NAME_MAX_LENGTH, 0))
	{
		VLIB_REPORT_ERROR(L"Failed to get the system locale");
	}

	LabelFont = new VFont(L"Microsoft YaHei UI", VFont::WEIGHT_NORMAL, VFont::STYLE_NORMAL, VFont::STRETCH_NORMAL, 12.f,
						  LocaleName);
}
VLabelCommonTheme::~VLabelCommonTheme()
{
	delete LabelFont;
}
VPushButtonTheme::VPushButtonTheme(const VPushButtonTheme &Theme)
{
	StaticTheme	 = Theme.StaticTheme;
	OnHoverTheme = Theme.OnHoverTheme;
	ActiveTheme	 = Theme.ActiveTheme;
	LabelFont	 = new VFont(*Theme.LabelFont);
	PlainText	 = Theme.PlainText;
	LocalTheme	 = Theme.StaticTheme;
}
VPushButtonTheme::VPushButtonTheme() : VLabelCommonTheme()
{
	StaticTheme.BackgroundColor			  = VColor::FromBYTERGBA(56, 56, 56, 0);
	StaticTheme.BorderColor				  = VColor::FromBYTERGBA(53, 53, 53, 255);
	StaticTheme.BorderThickness			  = 1.3f;
	StaticTheme.Radius					  = {5, 5};
	StaticTheme.TextColor				  = VColor::FromBYTERGBA(126, 126, 126, 255);
	StaticTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	OnHoverTheme.BackgroundColor		   = VColor::FromBYTERGBA(56, 56, 56, 255);
	OnHoverTheme.BorderColor			   = VColor::FromBYTERGBA(56, 56, 56, 255);
	OnHoverTheme.TextColor				   = VColor::FromBYTERGBA(126, 126, 126, 255);
	OnHoverTheme.Radius					   = {5, 5};
	OnHoverTheme.BorderThickness		   = 1.3f;
	OnHoverTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	ActiveTheme.BackgroundColor			  = VColor::FromBYTERGBA(98, 100, 167, 255);
	ActiveTheme.BorderColor				  = VColor::FromBYTERGBA(98, 100, 167, 255);
	ActiveTheme.TextColor				  = VColor::FromBYTERGBA(255, 255, 255, 255);
	ActiveTheme.Radius					  = {5, 5};
	ActiveTheme.BorderThickness			  = 1.3f;
	ActiveTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	LocalTheme = StaticTheme;

	LabelFont->SetParagraphAlignment(VFontParagraphAlignment::DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	LabelFont->SetLineAlignment(VFontAlignment::DWRITE_TEXT_ALIGNMENT_CENTER);
}

VTextLabelTheme::VTextLabelTheme() : VLabelCommonTheme()
{
	StaticTheme.BackgroundColor			  = VColor::FromBYTERGBA(56, 56, 56, 0);
	StaticTheme.BorderColor				  = VColor::FromBYTERGBA(53, 53, 53, 0);
	StaticTheme.BorderThickness			  = 1.3f;
	StaticTheme.Radius					  = {5, 5};
	StaticTheme.TextColor				  = VColor::FromBYTERGBA(126, 126, 126, 119);
	StaticTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	OnHoverTheme.BackgroundColor		   = VColor::FromBYTERGBA(56, 56, 56, 0);
	OnHoverTheme.BorderColor			   = VColor::FromBYTERGBA(56, 56, 56, 0);
	OnHoverTheme.TextColor				   = VColor::FromBYTERGBA(126, 126, 126, 119);
	OnHoverTheme.Radius					   = {5, 5};
	OnHoverTheme.BorderThickness		   = 1.3f;
	OnHoverTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	ActiveTheme.BackgroundColor			  = VColor::FromBYTERGBA(98, 100, 167, 0);
	ActiveTheme.BorderColor				  = VColor::FromBYTERGBA(98, 100, 167, 0);
	ActiveTheme.TextColor				  = VColor::FromBYTERGBA(255, 255, 255, 119);
	ActiveTheme.Radius					  = {5, 5};
	ActiveTheme.BorderThickness			  = 1.3f;
	ActiveTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	LocalTheme = StaticTheme;
}
VTextLabelTheme::VTextLabelTheme(const VTextLabelTheme &Theme)
{
	StaticTheme	 = Theme.StaticTheme;
	OnHoverTheme = Theme.OnHoverTheme;
	ActiveTheme	 = Theme.ActiveTheme;
	LabelFont	 = new VFont(*Theme.LabelFont);
	PlainText	 = Theme.PlainText;
	LocalTheme	 = Theme.StaticTheme;
}

VRadioButtonTheme::VRadioButtonTheme()
{
	StaticTheme.BackgroundColor			  = VColor::FromBYTERGBA(75, 75, 75, 0);
	StaticTheme.BorderColor				  = VColor::FromBYTERGBA(75, 75, 75, 255);
	StaticTheme.BorderThickness			  = 1.3f;
	StaticTheme.Radius					  = {5, 5};
	StaticTheme.TextColor				  = VColor::FromBYTERGBA(126, 126, 126, 119);
	StaticTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	OnHoverTheme.BackgroundColor		   = VColor::FromBYTERGBA(75, 75, 75, 255);
	OnHoverTheme.BorderColor			   = VColor::FromBYTERGBA(75, 75, 75, 255);
	OnHoverTheme.TextColor				   = VColor::FromBYTERGBA(126, 126, 126, 119);
	OnHoverTheme.Radius					   = {5, 5};
	OnHoverTheme.BorderThickness		   = 1.3f;
	OnHoverTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	ActiveTheme.BackgroundColor			  = VColor::FromBYTERGBA(98, 100, 167, 255);
	ActiveTheme.BorderColor				  = VColor::FromBYTERGBA(98, 100, 167, 255);
	ActiveTheme.TextColor				  = VColor::FromBYTERGBA(255, 255, 255, 119);
	ActiveTheme.Radius					  = {5, 5};
	ActiveTheme.BorderThickness			  = 1.3f;
	ActiveTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	LocalTheme = StaticTheme;
}
VRadioButtonTheme::VRadioButtonTheme(const VRadioButtonTheme &Theme)
{
	StaticTheme	 = Theme.StaticTheme;
	OnHoverTheme = Theme.OnHoverTheme;
	ActiveTheme	 = Theme.ActiveTheme;
	LocalTheme	 = Theme.StaticTheme;
	SwitchStatus = Theme.SwitchStatus;
}
VCircleScrollBarTheme::VCircleScrollBarTheme()
{
	StaticTheme.BackgroundColor			  = VColor::FromBYTERGBA(87, 87, 87, 255);
	StaticTheme.BorderColor				  = VColor::FromBYTERGBA(87, 87, 87, 255);
	StaticTheme.BorderThickness			  = 1.3f;
	StaticTheme.Radius					  = {5, 5};
	StaticTheme.TextColor				  = VColor::FromBYTERGBA(126, 126, 126, 255);
	StaticTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	OnHoverTheme.BackgroundColor		   = VColor::FromBYTERGBA(87, 87, 87, 255);
	OnHoverTheme.BorderColor			   = VColor::FromBYTERGBA(87, 87, 87, 255);
	OnHoverTheme.TextColor				   = VColor::FromBYTERGBA(126, 126, 126, 255);
	OnHoverTheme.Radius					   = {5, 5};
	OnHoverTheme.BorderThickness		   = 1.3f;
	OnHoverTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	ActiveTheme.BackgroundColor			  = VColor::FromBYTERGBA(98, 100, 167, 255);
	ActiveTheme.BorderColor				  = VColor::FromBYTERGBA(98, 100, 167, 255);
	ActiveTheme.TextColor				  = VColor::FromBYTERGBA(255, 255, 255, 255);
	ActiveTheme.Radius					  = {5, 5};
	ActiveTheme.BorderThickness			  = 1.3f;
	ActiveTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	LocalTheme = StaticTheme;
}
VCircleScrollBarTheme::VCircleScrollBarTheme(const VCircleScrollBarTheme &Theme)
{
	StaticTheme	 = Theme.StaticTheme;
	OnHoverTheme = Theme.OnHoverTheme;
	ActiveTheme	 = Theme.ActiveTheme;
	LocalTheme	 = Theme.StaticTheme;
}

VSliderStatusTheme::VSliderStatusTheme(const VSliderStatusTheme &Theme)
{
	BackgroundColor = Theme.BackgroundColor;
	BorderColor		= Theme.BorderColor;
}

VSliderAreaTheme::VSliderAreaTheme(const VSliderAreaTheme &Theme)
{
	LocalTheme = Theme.LocalTheme;
}

VSliderTheme::VSliderTheme(const VSliderTheme &ThemeObject)
{
	UnselectedArea = ThemeObject.UnselectedArea;
	SelectedArea   = ThemeObject.SelectedArea;
}
VSliderTheme::VSliderTheme()
{
	UnselectedArea.LocalTheme.BorderColor	  = VColor::FromBYTERGBA(58, 58, 58, 255);
	UnselectedArea.LocalTheme.BackgroundColor = VColor::FromBYTERGBA(58, 58, 58, 255);
	UnselectedArea.LocalTheme.BorderThickness = 0.f;

	SelectedArea.LocalTheme.BorderColor		= VColor::FromBYTERGBA(98, 100, 167, 255);
	SelectedArea.LocalTheme.BackgroundColor = VColor::FromBYTERGBA(98, 100, 167, 255);
	SelectedArea.LocalTheme.BorderThickness = 0.f;
}

VBlurLabelTheme::VBlurLabelTheme(const VBlurLabelTheme &ThemeObject)
{
	MixedColor	 = ThemeObject.MixedColor;
	BlurRadius	 = ThemeObject.BlurRadius;
	BorderRadius = ThemeObject.BorderRadius;
}
VBlurLabelTheme::VBlurLabelTheme()
{
	MixedColor	 = VColor::FromBYTERGBA(56, 56, 56, 219);
	BlurRadius	 = 23;
	BorderRadius = {0, 0};
}

VIconButtonStatus::VIconButtonStatus()
{
	Image	= nullptr;
	Opacity = 1.f;
}
VIconButtonStatus::VIconButtonStatus(const VIconButtonStatus &Status)
{
	Image	= Status.Image;
	Opacity = Status.Opacity;
}

VIconButtonTheme::VIconButtonTheme(const VIconButtonTheme &Theme)
{
	StaticTheme	 = Theme.StaticTheme;
	OnHoverTheme = Theme.OnHoverTheme;
	ActiveTheme	 = Theme.ActiveTheme;
	LocalTheme	 = Theme.StaticTheme;

	if (Theme.Image != nullptr)
	{
		Image = new VImage(*Theme.Image);
	}
}
VIconButtonTheme::VIconButtonTheme() : VLabelCommonTheme()
{
	StaticTheme.BackgroundColor			  = VColor::FromBYTERGBA(56, 56, 56, 0);
	StaticTheme.BorderColor				  = VColor::FromBYTERGBA(53, 53, 53, 0);
	StaticTheme.BorderThickness			  = 1.3f;
	StaticTheme.Radius					  = {5, 5};
	StaticTheme.TextColor				  = VColor::FromBYTERGBA(126, 126, 126, 255);
	StaticTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	OnHoverTheme.BackgroundColor		   = VColor::FromBYTERGBA(255, 255, 255, 25);
	OnHoverTheme.BorderColor			   = VColor::FromBYTERGBA(255, 255, 255, 25);
	OnHoverTheme.Radius					   = {5, 5};
	OnHoverTheme.BorderThickness		   = 1.3f;
	OnHoverTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	ActiveTheme.BackgroundColor			  = VColor::FromBYTERGBA(255, 255, 255, 81);
	ActiveTheme.BorderColor				  = VColor::FromBYTERGBA(255, 255, 255, 81);
	ActiveTheme.Radius					  = {5, 5};
	ActiveTheme.BorderThickness			  = 1.3f;
	ActiveTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	LocalTheme = StaticTheme;
	Image	   = nullptr;
}

VTextEditorTheme::VTextEditorTheme(const VTextEditorTheme &Theme)
{
	StaticTheme	 = Theme.StaticTheme;
	OnHoverTheme = Theme.OnHoverTheme;
	ActiveTheme	 = Theme.ActiveTheme;
	LabelFont	 = new VFont(*Theme.LabelFont);
	PlainText	 = Theme.PlainText;
	LocalTheme	 = Theme.StaticTheme;
	CursorColor	 = Theme.CursorColor;

	OnSelectedColor			  = Theme.OnSelectedColor;
	OnSelectedBackgroundColor = Theme.OnSelectedBackgroundColor;
	PlaceHolderColor		  = Theme.PlaceHolderColor;
}
VTextEditorTheme::VTextEditorTheme()
{
	StaticTheme.BackgroundColor			  = VColor::FromBYTERGBA(67, 67, 67, 255);
	StaticTheme.BorderColor				  = VColor::FromBYTERGBA(67, 67, 67, 255);
	StaticTheme.BorderThickness			  = 1.3f;
	StaticTheme.Radius					  = {5, 5};
	StaticTheme.TextColor				  = VColor::FromBYTERGBA(255, 255, 255, 150);
	StaticTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	OnHoverTheme.BackgroundColor		   = VColor::FromBYTERGBA(67, 67, 67, 255);
	OnHoverTheme.BorderColor			   = VColor::FromBYTERGBA(67, 67, 67, 255);
	OnHoverTheme.TextColor				   = VColor::FromBYTERGBA(255, 255, 255, 150);
	OnHoverTheme.Radius					   = {5, 5};
	OnHoverTheme.BorderThickness		   = 1.3f;
	OnHoverTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	ActiveTheme.BackgroundColor			  = VColor::FromBYTERGBA(67, 67, 67, 255);
	ActiveTheme.BorderColor				  = VColor::FromBYTERGBA(99, 101, 181, 255);
	ActiveTheme.TextColor				  = VColor::FromBYTERGBA(255, 255, 255, 255);
	ActiveTheme.Radius					  = {5, 5};
	ActiveTheme.BorderThickness			  = 1.3f;
	ActiveTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	CursorColor = VColor::FromBYTERGBA(255, 255, 255);

	LocalTheme = StaticTheme;

	LabelFont->SetParagraphAlignment(VFontParagraphAlignment::DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	LabelFont->SetLineAlignment(VFontAlignment::DWRITE_TEXT_ALIGNMENT_LEADING);

	OnSelectedColor			  = VColor::FromBYTERGBA(255, 255, 255, 255);
	OnSelectedBackgroundColor = VColor::FromBYTERGBA(255, 255, 255, 40);

	PlaceHolderColor = VColor::FromBYTERGBA(255, 255, 255, 150);
}

VViewScrollerButtonTheme::VViewScrollerButtonTheme()
{
	StaticTheme.BackgroundColor			  = VColor::FromBYTERGBA(80, 80, 80, 99);
	StaticTheme.BorderColor				  = VColor::FromBYTERGBA(80, 80, 80, 99);
	StaticTheme.BorderThickness			  = 1.3f;
	StaticTheme.Radius					  = {5, 5};
	StaticTheme.TextColor				  = VColor::FromBYTERGBA(126, 126, 126, 255);
	StaticTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	OnHoverTheme.BackgroundColor		   = VColor::FromBYTERGBA(80, 80, 80, 255);
	OnHoverTheme.BorderColor			   = VColor::FromBYTERGBA(80, 80, 80, 255);
	OnHoverTheme.Radius					   = {5, 5};
	OnHoverTheme.BorderThickness		   = 1.3f;
	OnHoverTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	ActiveTheme.BackgroundColor			  = VColor::FromBYTERGBA(98, 100, 167, 255);
	ActiveTheme.BorderColor				  = VColor::FromBYTERGBA(98, 100, 167, 255);
	ActiveTheme.Radius					  = {5, 5};
	ActiveTheme.BorderThickness			  = 1.3f;
	ActiveTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	LocalTheme = StaticTheme;
}
VViewScrollerButtonTheme::VViewScrollerButtonTheme(const VViewScrollerButtonTheme &Theme)
{
	StaticTheme	 = Theme.StaticTheme;
	OnHoverTheme = Theme.OnHoverTheme;
	ActiveTheme	 = Theme.ActiveTheme;

	LocalTheme = StaticTheme;
}

VViewScrollerTheme::VViewScrollerTheme()
{
	StaticTheme.BackgroundColor			  = VColor::FromBYTERGBA(54, 54, 54, 81);
	StaticTheme.BorderColor				  = VColor::FromBYTERGBA(54, 54, 54, 81);
	StaticTheme.BorderThickness			  = 1.3f;
	StaticTheme.Radius					  = {5, 5};
	StaticTheme.TextColor				  = VColor::FromBYTERGBA(126, 126, 126, 255);
	StaticTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	OnHoverTheme.BackgroundColor		   = VColor::FromBYTERGBA(54, 54, 54, 81);
	OnHoverTheme.BorderColor			   = VColor::FromBYTERGBA(54, 54, 54, 81);
	OnHoverTheme.Radius					   = {5, 5};
	OnHoverTheme.BorderThickness		   = 1.3f;
	OnHoverTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	ActiveTheme.BackgroundColor			  = VColor::FromBYTERGBA(54, 54, 54, 255);
	ActiveTheme.BorderColor				  = VColor::FromBYTERGBA(54, 54, 54, 255);
	ActiveTheme.Radius					  = {5, 5};
	ActiveTheme.BorderThickness			  = 1.3f;
	ActiveTheme.AnimationInterpolatorType = VInterpolatorType::AccelerateInterpolator;

	LocalTheme = StaticTheme;
}
VViewScrollerTheme::VViewScrollerTheme(const VViewScrollerTheme &Theme)
{
	StaticTheme	 = Theme.StaticTheme;
	OnHoverTheme = Theme.OnHoverTheme;
	ActiveTheme	 = Theme.ActiveTheme;

	LocalTheme = StaticTheme;
}

VViewLabelTheme::VViewLabelTheme()
{
	BackgroundColor = VColor(0.f, 0.f, 0.f, 0.f);
	BorderColor		= VColor(0.f, 0.f, 0.f, 0.f);

	Radius = {8, 8};
}

VViewLabelTheme::VViewLabelTheme(const VViewLabelTheme &Theme)
{
	BackgroundColor = Theme.BackgroundColor;
	BorderColor		= Theme.BorderColor;
	Radius			= Theme.Radius;
}

} // namespace Core

VLIB_END_NAMESPACE