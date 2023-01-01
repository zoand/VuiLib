﻿// #define _SILENCE_AMP_DEPRECATION_WARNINGS
// #pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#include "./include/core/control/vlineeditor.h"
#include "./include/core/control/vswitchgroup.h"
#include "./include/core/control/vscroller.h"
#include "./include/core/control/vviewlabel.h"
#include "./include/core/visual/vvisual.h"
#include "./include/core/animation/vanimation.h"

#include "./include/core/uibasic/vsmarttimer.h"
#include "./include/core/control/vcanvas.h"

#include "./include/core/control/veditor.h"

#include "./include/vml/vmlwidget.h"
#include "./include/kits/vallocator.h"

#include <iostream>

#define fn  auto
#define var auto

#define format_parameter(variable) ((const char* const)variable)

fn main() -> int {
	var Application = Core::VApplication();
	var MainWindow  = VML::VMLMainWindow(640, 800, &Application);
	
	MainWindow.Show();
	MainWindow.GetLocalWinId();

	// MainWindow.LoadVML(L"./testvml.xml", VML::VMLParserParseMode::FromFile);

	Core::VEditor* Editor = new Core::VEditor(1200, 840, &MainWindow);
	Core::VScaleLayout* Layout = new Core::VScaleLayout(Editor, Editor->GetParent());
	Layout->SetWidthScalePercent(1.f);
	Layout->SetHeightScalePercent(1.f);

	Editor->Move(0, 0);
	auto Theme = Editor->GetTheme();
	delete Theme->LabelFont;
	Theme->LabelFont = new Core::VFont(L"JetBrains Mono", Core::VFont::FontWeight::WEIGHT_NORMAL, Core::VFont::FontStyle::STYLE_NORMAL, Core::VFont::FontStretch::STRETCH_NORMAL, 11.F, L"ZH-CN");
	Theme->LabelFont->SetParagraphAlignment(Core::VFontParagraphAlignment::DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
	Editor->ResetTextLayout();
	Editor->SetPlaneText(LR"(#pragma once

#include "../object/vuiobject.h"
#include "../uibasic/vsmarttimer.h"
#include "vabstractbutton.h"

#include <map>

VLIB_BEGIN_NAMESPACE

namespace Core {
	enum class VEditorCaretSelectMode {
		Left, Right, Up, Down
	};
	struct VEditorCaret {
		std::wstring*		   CacheTargetPtr;

		bool				   InSelecting;

		VEditorCaretSelectMode SelectMode;

		int					   CaretStart;
		int					   CaretEnd;
							   
		void				   CaretSelectionTurnUp(IDWriteTextLayout* TextLayout);
		void				   CaretSelectionTurnDown(IDWriteTextLayout* TextLayout);
		void				   CaretSelectionTurnLeft();
		void				   CaretSelectionTurnRight();

		void				   CaretSelectionTurnLineHead(IDWriteTextLayout* TextLayout);
		void				   CaretSelectionTurnLineEnd(IDWriteTextLayout* TextLayout);

		void				   CaretSelectAll();

		void				   CaretTurnLeft();
		void				   CaretTurnRight();
		void				   CaretTurnUp(IDWriteTextLayout* TextLayout);
		void				   CaretTurnDown(IDWriteTextLayout* TextLayout);

		void				   CaretTurnLineHead(IDWriteTextLayout* TextLayout);
		void				   CaretTurnLineEnd(IDWriteTextLayout* TextLayout);

		void				   CaretPageUp();
		void				   CaretPageEnd();

		void				   SetValidCaretRange();

		void				   SetCaretByMousePosition(const int& X, const int& Y, IDWriteTextLayout* TextLayout);
		void				   SetCaretSelectionByMousePosition(const int& X, const int& Y, IDWriteTextLayout* TextLayout);

		VPoint				   GetCaretPosition(IDWriteTextLayout* TextLayout);
		DWRITE_TEXT_RANGE	   GetTextRange();
	};

	class VEditor : public VAbstractButton {
	public:
		VEditor(VUIObject* Parent);
		VEditor(const int& Width, const int& Height, VUIObject* Parent);

	public:
		void OnPaint(VCanvasPainter* Painter) override;

	public:
		void SetPlaneText(const std::wstring& PlaneText);

	public:
		void ResetCaretStatus();
		void ResetTextLayout();

	public:
		void LeftClickedDown() override;
		void GotMouseFocus() override;
		void OnMessage(VMessage* Message) override;

	public:
		void CheckFrame() override;

	private:
		bool ClearSelectArea();
		void BackCharacter();
		void DeleteCharacter();
		void AddCharaceter(const wchar_t& Character);

	private:
		int GetMaxOffsetY();

	private:
		void SetScroller();

	private:
		bool IsASCIICharacter(const wchar_t& ASCIICode);

	private:
		void CopyClipboard();
		void WriteClipboard();

	public:
		std::map<ID2D1Effect*, DWRITE_TEXT_RANGE> TextEffect;

	private:
		VSmartTimer								  CaretTimer;
		bool									  ShowCaret;
		bool									  UserInOperating;
		bool									  FirstBackOff;

		long int								  OffsetY;
		long int								  OffsetX;

		std::wstring							  InEditingText;
		VTextEditorTheme*						  Theme;

		VEditorCaret							  Caret;

		Microsoft::WRL::ComPtr<IDWriteTextLayout> LocalTextLayout;

	private:
		bool InMouseDragSelecting;
		bool UsedComboKey;

	private:
		VBasicTimer             AnimationFrameTimer;
		VBasicTimer				BackoffTimer;
		VBasicTimer				BackoffResetTimer;
		VAnimationInterpolator* Interpolator;

		time_t					LastBackOffTime;

		VLabelStatusTheme       OldTheme;
		VLabelStatusTheme       TargetTheme;

		bool                    InAnimation = false;
	};
}

VLIB_END_NAMESPACE)");

	return Application.Exec();
}