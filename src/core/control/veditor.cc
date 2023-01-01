#include "../../../include/core/control/veditor.h"

VLIB_BEGIN_NAMESPACE

namespace Core {
	void VEditorCaret::CaretSelectionTurnUp(IDWriteTextLayout* TextLayout) {
		InSelecting = true;

		if (CaretStart == CaretEnd) {
			DWRITE_TEXT_METRICS				 TextMetrics;
			std::vector<DWRITE_LINE_METRICS> LineMetrics;

			TextLayout->GetMetrics(&TextMetrics);

			LineMetrics.resize(TextMetrics.lineCount);

			TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

			UINT32 Line = 0;
			UINT32 LinePosition		= 0;
			UINT32 NextLinePosition = 0;
			UINT32 LineCount	    = static_cast<UINT32>(LineMetrics.size());
			for (; Line < LineCount; ++Line) {
				LinePosition	 = NextLinePosition;
				NextLinePosition = LinePosition + LineMetrics[Line].length;

				if (NextLinePosition > CaretStart) {
					break;
				}
			}

			if (Line > LineCount - 1) {
				Line = LineCount - 1;
			}

			if (Line <= 0) {
				return;
			}

			--Line;
			LinePosition -= LineMetrics[Line].length;

			DWRITE_HIT_TEST_METRICS HitTestMetrics;

			FLOAT CaretX		  = 0;
			FLOAT CaretY		  = 0;
			FLOAT UnusedParemeter = 0;

			BOOL  IsInside		  = FALSE;
			BOOL  IsTrailingHit	  = FALSE;

			TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &HitTestMetrics);
			TextLayout->HitTestTextPosition(LinePosition, FALSE, &UnusedParemeter, &CaretY, &HitTestMetrics);
			TextLayout->HitTestPoint(CaretX, CaretY, &IsTrailingHit, &IsInside, &HitTestMetrics);

			CaretStart = HitTestMetrics.textPosition;

			if (IsTrailingHit) {
				CaretStart = CacheTargetPtr->size();
			}

			SetValidCaretRange();

			return;
		}
		else {
			switch (SelectMode) {
			case VEditorCaretSelectMode::Left: {
				DWRITE_TEXT_METRICS				 TextMetrics;
				std::vector<DWRITE_LINE_METRICS> LineMetrics;

				TextLayout->GetMetrics(&TextMetrics);

				LineMetrics.resize(TextMetrics.lineCount);

				TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

				UINT32 Line = 0;
				UINT32 LinePosition		= 0;
				UINT32 NextLinePosition = 0;
				UINT32 LineCount	    = static_cast<UINT32>(LineMetrics.size());
				for (; Line < LineCount; ++Line) {
					LinePosition	 = NextLinePosition;
					NextLinePosition = LinePosition + LineMetrics[Line].length;

					if (NextLinePosition > CaretStart) {
						break;
					}
				}

				if (Line > LineCount - 1) {
					Line = LineCount - 1;
				}

				if (Line <= 0) {
					return;
				}

				--Line;
				LinePosition -= LineMetrics[Line].length;

				DWRITE_HIT_TEST_METRICS HitTestMetrics;

				FLOAT CaretX		  = 0;
				FLOAT CaretY		  = 0;
				FLOAT UnusedParemeter = 0;

				BOOL  IsInside		  = FALSE;
				BOOL  IsTrailingHit	  = FALSE;

				TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &HitTestMetrics);
				TextLayout->HitTestTextPosition(LinePosition, FALSE, &UnusedParemeter, &CaretY, &HitTestMetrics);
				TextLayout->HitTestPoint(CaretX, CaretY, &IsTrailingHit, &IsInside, &HitTestMetrics);

				CaretStart = HitTestMetrics.textPosition;

				if (IsTrailingHit) {
					CaretStart = CacheTargetPtr->size();
				}

				SetValidCaretRange();

				return;
			}
			case VEditorCaretSelectMode::Right: {
				CaretEnd = CaretStart;

				DWRITE_TEXT_METRICS				 TextMetrics;
				std::vector<DWRITE_LINE_METRICS> LineMetrics;

				TextLayout->GetMetrics(&TextMetrics);

				LineMetrics.resize(TextMetrics.lineCount);

				TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

				UINT32 Line = 0;
				UINT32 LinePosition		= 0;
				UINT32 NextLinePosition = 0;
				UINT32 LineCount	    = static_cast<UINT32>(LineMetrics.size());
				for (; Line < LineCount; ++Line) {
					LinePosition	 = NextLinePosition;
					NextLinePosition = LinePosition + LineMetrics[Line].length;

					if (NextLinePosition > CaretStart) {
						break;
					}
				}

				if (Line > LineCount - 1) {
					Line = LineCount - 1;
				}

				if (Line <= 0) {
					return;
				}

				--Line;
				LinePosition -= LineMetrics[Line].length;

				DWRITE_HIT_TEST_METRICS HitTestMetrics;

				FLOAT CaretX		  = 0;
				FLOAT CaretY		  = 0;
				FLOAT UnusedParemeter = 0;

				BOOL  IsInside		  = FALSE;
				BOOL  IsTrailingHit	  = FALSE;

				TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &HitTestMetrics);
				TextLayout->HitTestTextPosition(LinePosition, FALSE, &UnusedParemeter, &CaretY, &HitTestMetrics);
				TextLayout->HitTestPoint(CaretX, CaretY, &IsTrailingHit, &IsInside, &HitTestMetrics);

				CaretStart = HitTestMetrics.textPosition;

				if (IsTrailingHit) {
					CaretStart = CacheTargetPtr->size();
				}

				SetValidCaretRange();

				return;
			}
			}
		}
	}
	void VEditorCaret::CaretSelectionTurnDown(IDWriteTextLayout* TextLayout) {
		InSelecting = true;

		if (CaretStart == CaretEnd) {
			DWRITE_TEXT_METRICS				 TextMetrics;
			std::vector<DWRITE_LINE_METRICS> LineMetrics;

			TextLayout->GetMetrics(&TextMetrics);

			LineMetrics.resize(TextMetrics.lineCount);

			TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

			UINT32 Line				= 0;
			UINT32 LinePosition		= 0;
			UINT32 NextLinePosition = 0;
			UINT32 LineCount	    = static_cast<UINT32>(LineMetrics.size());
			for (; Line < LineCount; ++Line) {
				LinePosition	 = NextLinePosition;
				NextLinePosition = LinePosition + LineMetrics[Line].length;

				if (NextLinePosition > CaretStart) {
					break;
				}
			}

			if (Line > LineCount - 1) {
				Line = LineCount - 1;
			}

			LinePosition += LineMetrics[Line].length;

			++Line;

			if (Line >= LineMetrics.size()) {
				return;
			}

			DWRITE_HIT_TEST_METRICS HitTestMetrics;

			FLOAT CaretX		  = 0;
			FLOAT CaretY		  = 0;
			FLOAT UnusedParemeter = 0;

			BOOL  IsInside		  = FALSE;
			BOOL  IsTrailingHit	  = FALSE;

			TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &HitTestMetrics);
			TextLayout->HitTestTextPosition(LinePosition, FALSE, &UnusedParemeter, &CaretY, &HitTestMetrics);
			TextLayout->HitTestPoint(CaretX, CaretY, &IsTrailingHit, &IsInside, &HitTestMetrics);

			CaretStart = HitTestMetrics.textPosition;

			if (IsTrailingHit) {
				CaretStart = CacheTargetPtr->size();
			}

			CaretEnd = CaretStart;

			SetValidCaretRange();

			return;
		}
		else {
			switch (SelectMode) {
			case VEditorCaretSelectMode::Left: {
				DWRITE_TEXT_METRICS				 TextMetrics;
				std::vector<DWRITE_LINE_METRICS> LineMetrics;

				TextLayout->GetMetrics(&TextMetrics);

				LineMetrics.resize(TextMetrics.lineCount);

				TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

				UINT32 Line = 0;
				UINT32 LinePosition		= 0;
				UINT32 NextLinePosition = 0;
				UINT32 LineCount	    = static_cast<UINT32>(LineMetrics.size());
				for (; Line < LineCount; ++Line) {
					LinePosition	 = NextLinePosition;
					NextLinePosition = LinePosition + LineMetrics[Line].length;

					if (NextLinePosition > CaretStart) {
						break;
					}
				}

				if (Line > LineCount - 1) {
					Line = LineCount - 1;
				}

				LinePosition += LineMetrics[Line].length;

				++Line;

				if (Line >= LineMetrics.size()) {
					return;
				}

				DWRITE_HIT_TEST_METRICS HitTestMetrics;

				FLOAT CaretX		  = 0;
				FLOAT CaretY		  = 0;
				FLOAT UnusedParemeter = 0;

				BOOL  IsInside		  = FALSE;
				BOOL  IsTrailingHit	  = FALSE;

				TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &HitTestMetrics);
				TextLayout->HitTestTextPosition(LinePosition, FALSE, &UnusedParemeter, &CaretY, &HitTestMetrics);
				TextLayout->HitTestPoint(CaretX, CaretY, &IsTrailingHit, &IsInside, &HitTestMetrics);

				CaretStart = HitTestMetrics.textPosition;

				if (IsTrailingHit) {
					CaretStart = CacheTargetPtr->size();
				}

				SetValidCaretRange();

				return;
			}
			case VEditorCaretSelectMode::Right: {
				CaretEnd = CaretStart;

				DWRITE_TEXT_METRICS				 TextMetrics;
				std::vector<DWRITE_LINE_METRICS> LineMetrics;

				TextLayout->GetMetrics(&TextMetrics);

				LineMetrics.resize(TextMetrics.lineCount);

				TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

				UINT32 Line = 0;
				UINT32 LinePosition		= 0;
				UINT32 NextLinePosition = 0;
				UINT32 LineCount	    = static_cast<UINT32>(LineMetrics.size());
				for (; Line < LineCount; ++Line) {
					LinePosition	 = NextLinePosition;
					NextLinePosition = LinePosition + LineMetrics[Line].length;

					if (NextLinePosition > CaretStart) {
						break;
					}
				}

				if (Line > LineCount - 1) {
					Line = LineCount - 1;
				}

				LinePosition += LineMetrics[Line].length;

				++Line;

				if (Line >= LineMetrics.size()) {
					return;
				}

				DWRITE_HIT_TEST_METRICS HitTestMetrics;

				FLOAT CaretX		  = 0;
				FLOAT CaretY		  = 0;
				FLOAT UnusedParemeter = 0;

				BOOL  IsInside		  = FALSE;
				BOOL  IsTrailingHit	  = FALSE;

				TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &HitTestMetrics);
				TextLayout->HitTestTextPosition(LinePosition, FALSE, &UnusedParemeter, &CaretY, &HitTestMetrics);
				TextLayout->HitTestPoint(CaretX, CaretY, &IsTrailingHit, &IsInside, &HitTestMetrics);

				CaretStart = HitTestMetrics.textPosition;

				if (IsTrailingHit) {
					CaretStart = CacheTargetPtr->size();
				}

				SetValidCaretRange();

				return;
			}
			}
		}
	}
	void VEditorCaret::CaretSelectionTurnLeft() {
		InSelecting = true;

		if (CaretStart == CaretEnd) {
			SelectMode = VEditorCaretSelectMode::Left;

			if (CaretStart - 1 >= 0) {
				CaretStart -= 1;
			}

			return;
		}
		else {
			switch (SelectMode) {
			case VEditorCaretSelectMode::Left: {
				if (CaretStart - 1 >= 0) {
					CaretStart -= 1;
				}

				return;
			}
			case VEditorCaretSelectMode::Right: {
				if (CaretEnd - 1 >= 0) {
					CaretEnd -= 1;

					if (CaretEnd <= CaretStart) {
						SelectMode = VEditorCaretSelectMode::Right;
					}
				}

				return;
			}
			}
		}

		SetValidCaretRange();
	}
	void VEditorCaret::CaretSelectionTurnRight() {
		InSelecting = true;

		if (CaretStart == CaretEnd) {
			SelectMode = VEditorCaretSelectMode::Right;

			if (CaretEnd + 1 <= CacheTargetPtr->size()) {
				CaretEnd += 1;
			}

			return;
		}
		else {
			switch (SelectMode) {
			case VEditorCaretSelectMode::Left: {
				if (CaretStart + 1 <= CacheTargetPtr->size()) {
					CaretStart += 1;

					if (CaretStart >= CaretEnd) {
						SelectMode = VEditorCaretSelectMode::Right;
					}
				}

				return;

			}
			case VEditorCaretSelectMode::Right: {
				if (CaretEnd + 1 <= CacheTargetPtr->size()) {
					CaretEnd += 1;
				}

				return;
			}
			}
		}

		SetValidCaretRange();
	}

	void VEditorCaret::CaretTurnUp(IDWriteTextLayout* TextLayout) {
		if (CaretStart == CaretEnd) {
			DWRITE_TEXT_METRICS				 TextMetrics;
			std::vector<DWRITE_LINE_METRICS> LineMetrics;

			TextLayout->GetMetrics(&TextMetrics);

			LineMetrics.resize(TextMetrics.lineCount);

			TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

			UINT32 Line = 0;
			UINT32 LinePosition = 0;
			UINT32 NextLinePosition = 0;
			UINT32 LineCount = static_cast<UINT32>(LineMetrics.size());
			for (; Line < LineCount; ++Line) {
				LinePosition = NextLinePosition;
				NextLinePosition = LinePosition + LineMetrics[Line].length;

				if (NextLinePosition > CaretStart) {
					break;
				}
			}

			if (Line > LineCount - 1) {
				Line = LineCount - 1;
			}

			if (Line <= 0) {
				return;
			}

			--Line;
			LinePosition -= LineMetrics[Line].length;

			DWRITE_HIT_TEST_METRICS HitTestMetrics;

			FLOAT CaretX = 0;
			FLOAT CaretY = 0;
			FLOAT UnusedParemeter = 0;

			BOOL  IsInside = FALSE;
			BOOL  IsTrailingHit = FALSE;

			TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &HitTestMetrics);
			TextLayout->HitTestTextPosition(LinePosition, FALSE, &UnusedParemeter, &CaretY, &HitTestMetrics);

			CaretY += 12;

			TextLayout->HitTestPoint(CaretX, CaretY, &IsTrailingHit, &IsInside, &HitTestMetrics);

			CaretStart = HitTestMetrics.textPosition;

			CaretEnd = CaretStart;

			return;
		}
		else {
			switch (SelectMode) {
			case VEditorCaretSelectMode::Left: {
				DWRITE_TEXT_METRICS				 TextMetrics;
				std::vector<DWRITE_LINE_METRICS> LineMetrics;

				TextLayout->GetMetrics(&TextMetrics);

				LineMetrics.resize(TextMetrics.lineCount);

				TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

				UINT32 Line = 0;
				UINT32 LinePosition = 0;
				UINT32 NextLinePosition = 0;
				UINT32 LineCount = static_cast<UINT32>(LineMetrics.size());
				for (; Line < LineCount; ++Line) {
					LinePosition = NextLinePosition;
					NextLinePosition = LinePosition + LineMetrics[Line].length;

					if (NextLinePosition > CaretStart) {
						break;
					}
				}

				if (Line > LineCount - 1) {
					Line = LineCount - 1;
				}

				if (Line <= 0) {
					return;
				}

				--Line;
				LinePosition -= LineMetrics[Line].length;

				DWRITE_HIT_TEST_METRICS HitTestMetrics;

				FLOAT CaretX = 0;
				FLOAT CaretY = 0;
				FLOAT UnusedParemeter = 0;

				BOOL  IsInside = FALSE;
				BOOL  IsTrailingHit = FALSE;

				TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &HitTestMetrics);
				TextLayout->HitTestTextPosition(LinePosition, FALSE, &UnusedParemeter, &CaretY, &HitTestMetrics);

				CaretY += 12;

				TextLayout->HitTestPoint(CaretX, CaretY, &IsTrailingHit, &IsInside, &HitTestMetrics);

				CaretStart = HitTestMetrics.textPosition;

				CaretEnd = CaretStart;

				return;
			}
			case VEditorCaretSelectMode::Right: {
				DWRITE_TEXT_METRICS				 TextMetrics;
				std::vector<DWRITE_LINE_METRICS> LineMetrics;

				TextLayout->GetMetrics(&TextMetrics);

				LineMetrics.resize(TextMetrics.lineCount);

				TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

				UINT32 Line = 0;
				UINT32 LinePosition = 0;
				UINT32 NextLinePosition = 0;
				UINT32 LineCount = static_cast<UINT32>(LineMetrics.size());
				for (; Line < LineCount; ++Line) {
					LinePosition = NextLinePosition;
					NextLinePosition = LinePosition + LineMetrics[Line].length;

					if (NextLinePosition > CaretStart) {
						break;
					}
				}

				if (Line > LineCount - 1) {
					Line = LineCount - 1;
				}

				if (Line <= 0) {
					return;
				}

				--Line;
				LinePosition -= LineMetrics[Line].length;

				DWRITE_HIT_TEST_METRICS HitTestMetrics;

				FLOAT CaretX = 0;
				FLOAT CaretY = 0;
				FLOAT UnusedParemeter = 0;

				BOOL  IsInside = FALSE;
				BOOL  IsTrailingHit = FALSE;

				TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &HitTestMetrics);
				TextLayout->HitTestTextPosition(LinePosition, FALSE, &UnusedParemeter, &CaretY, &HitTestMetrics);

				CaretY += 12;

				TextLayout->HitTestPoint(CaretX, CaretY, &IsTrailingHit, &IsInside, &HitTestMetrics);

				CaretStart = HitTestMetrics.textPosition;

				CaretEnd = CaretStart;

				return;
			}
			}
		}
	}
	void VEditorCaret::CaretTurnDown(IDWriteTextLayout* TextLayout) {
		if (CaretStart == CaretEnd) {
			DWRITE_TEXT_METRICS				 TextMetrics;
			std::vector<DWRITE_LINE_METRICS> LineMetrics;

			TextLayout->GetMetrics(&TextMetrics);

			LineMetrics.resize(TextMetrics.lineCount);

			TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

			UINT32 Line = 0;
			UINT32 LinePosition = 0;
			UINT32 NextLinePosition = 0;
			UINT32 LineCount = static_cast<UINT32>(LineMetrics.size());
			for (; Line < LineCount; ++Line) {
				LinePosition	 = NextLinePosition;
				NextLinePosition = LinePosition + LineMetrics[Line].length;

				if (NextLinePosition > CaretStart) {
					LinePosition += LineMetrics[Line].length;

					break;
				}
			}

			if (Line > LineCount - 1) {
				Line = LineCount - 1;
			}

			LinePosition += LineMetrics[Line].length;
			++Line;

			if (Line >= LineMetrics.size()) {
				return;
			}

			DWRITE_HIT_TEST_METRICS HitTestMetrics;

			FLOAT CaretX = 0;
			FLOAT CaretY = 0;
			FLOAT UnusedParemeter = 0;

			BOOL  IsInside	    = FALSE;
			BOOL  IsTrailingHit = FALSE;

			TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &HitTestMetrics);
			TextLayout->HitTestTextPosition(NextLinePosition, FALSE, &UnusedParemeter, &CaretY, &HitTestMetrics);

			CaretY += 12;

			TextLayout->HitTestPoint(CaretX, CaretY, &IsTrailingHit, &IsInside, &HitTestMetrics);

			CaretStart = HitTestMetrics.textPosition;

			if (IsTrailingHit) {
				CaretStart += HitTestMetrics.length;
			}

			CaretEnd = CaretStart;

			return;
		}
		else {
			switch (SelectMode) {
			case VEditorCaretSelectMode::Left: {
				DWRITE_TEXT_METRICS				 TextMetrics;
				std::vector<DWRITE_LINE_METRICS> LineMetrics;

				TextLayout->GetMetrics(&TextMetrics);

				LineMetrics.resize(TextMetrics.lineCount);

				TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

				UINT32 Line = 0;
				UINT32 LinePosition = 0;
				UINT32 NextLinePosition = 0;
				UINT32 LineCount = static_cast<UINT32>(LineMetrics.size());
				for (; Line < LineCount; ++Line) {
					LinePosition = NextLinePosition;
					NextLinePosition = LinePosition + LineMetrics[Line].length;

					if (NextLinePosition > CaretStart) {
						break;
					}
				}

				if (Line > LineCount - 1) {
					Line = LineCount - 1;
				}

				LinePosition += LineMetrics[Line].length;

				++Line;

				if (Line >= LineMetrics.size()) {
					return;
				}

				DWRITE_HIT_TEST_METRICS HitTestMetrics;

				FLOAT CaretX = 0;
				FLOAT CaretY = 0;
				FLOAT UnusedParemeter = 0;

				BOOL  IsInside = FALSE;
				BOOL  IsTrailingHit = FALSE;

				TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &HitTestMetrics);
				TextLayout->HitTestTextPosition(LinePosition, FALSE, &UnusedParemeter, &CaretY, &HitTestMetrics);

				CaretY += 12;

				TextLayout->HitTestPoint(CaretX, CaretY, &IsTrailingHit, &IsInside, &HitTestMetrics);

				CaretStart = HitTestMetrics.textPosition;

				CaretEnd = CaretStart;

				return;
			}
			case VEditorCaretSelectMode::Right: {
				DWRITE_TEXT_METRICS				 TextMetrics;
				std::vector<DWRITE_LINE_METRICS> LineMetrics;

				TextLayout->GetMetrics(&TextMetrics);

				LineMetrics.resize(TextMetrics.lineCount);

				TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

				UINT32 Line = 0;
				UINT32 LinePosition = 0;
				UINT32 NextLinePosition = 0;
				UINT32 LineCount = static_cast<UINT32>(LineMetrics.size());
				for (; Line < LineCount; ++Line) {
					LinePosition = NextLinePosition;
					NextLinePosition = LinePosition + LineMetrics[Line].length;

					if (NextLinePosition > CaretStart) {
						break;
					}
				}

				if (Line > LineCount - 1) {
					Line = LineCount - 1;
				}

				LinePosition += LineMetrics[Line].length;

				++Line;

				if (Line >= LineMetrics.size()) {
					return;
				}

				DWRITE_HIT_TEST_METRICS HitTestMetrics;

				FLOAT CaretX = 0;
				FLOAT CaretY = 0;
				FLOAT UnusedParemeter = 0;

				BOOL  IsInside = FALSE;
				BOOL  IsTrailingHit = FALSE;

				TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &HitTestMetrics);
				TextLayout->HitTestTextPosition(LinePosition, FALSE, &UnusedParemeter, &CaretY, &HitTestMetrics);

				CaretY += 12;

				TextLayout->HitTestPoint(CaretX, CaretY, &IsTrailingHit, &IsInside, &HitTestMetrics);

				CaretStart = HitTestMetrics.textPosition;

				CaretEnd = CaretStart;

				return;
			}
			}
		}
	}
	void VEditorCaret::CaretTurnLineHead(IDWriteTextLayout* TextLayout) {
		DWRITE_TEXT_METRICS				 TextMetrics;
		std::vector<DWRITE_LINE_METRICS> LineMetrics;

		TextLayout->GetMetrics(&TextMetrics);

		LineMetrics.resize(TextMetrics.lineCount);

		TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

		UINT32 Line = 0;
		UINT32 LinePosition = 0;
		UINT32 LineCount = static_cast<UINT32>(LineMetrics.size());
		for (; Line < LineCount; ++Line) {
			LinePosition += LineMetrics[Line].length;

			if (LinePosition > CaretStart) {
				break;
			}
		}

		if (Line >= LineCount) {
			Line = LineCount - 1;
		}

		LinePosition -= LineMetrics[Line].length;

		CaretStart = LinePosition;
		CaretEnd   = CaretStart;
	}
	void VEditorCaret::CaretTurnLineEnd(IDWriteTextLayout* TextLayout) {
		DWRITE_TEXT_METRICS				 TextMetrics;
		std::vector<DWRITE_LINE_METRICS> LineMetrics;

		TextLayout->GetMetrics(&TextMetrics);

		LineMetrics.resize(TextMetrics.lineCount);

		TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

		UINT32 Line		    = 0;
		UINT32 LinePosition = 0;
		UINT32 LineCount	= static_cast<UINT32>(LineMetrics.size());
		for (; Line < LineCount; ++Line) {
			LinePosition += LineMetrics[Line].length;

			if (LinePosition > CaretStart) {
				break;
			}
		}

		CaretStart = LinePosition - 1;

		if (LinePosition < CacheTargetPtr->size() &&
			CacheTargetPtr->at(LinePosition) == L'\n') {
			--CaretStart;
		}
		if (LinePosition >= CacheTargetPtr->size()) {
			++CaretStart;
		}

		CaretEnd   = CaretStart;
	}
	void VEditorCaret::CaretSelectionTurnLineHead(IDWriteTextLayout* TextLayout) {
		DWRITE_TEXT_METRICS				 TextMetrics;
		std::vector<DWRITE_LINE_METRICS> LineMetrics;

		TextLayout->GetMetrics(&TextMetrics);

		LineMetrics.resize(TextMetrics.lineCount);

		TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

		UINT32 Line = 0;
		UINT32 LinePosition = 0;
		UINT32 LineCount = static_cast<UINT32>(LineMetrics.size());
		for (; Line < LineCount; ++Line) {
			LinePosition += LineMetrics[Line].length;

			if (LinePosition > CaretStart) {
				break;
			}
		}

		if (Line >= LineMetrics.size()) {
			Line = LineMetrics.size() - 1;
		}

		LinePosition -= LineMetrics[Line].length;

		CaretStart = LinePosition;

		InSelecting = true;
		SelectMode = VEditorCaretSelectMode::Left;
	}
	void VEditorCaret::CaretSelectionTurnLineEnd(IDWriteTextLayout* TextLayout) {
		DWRITE_TEXT_METRICS				 TextMetrics;
		std::vector<DWRITE_LINE_METRICS> LineMetrics;

		TextLayout->GetMetrics(&TextMetrics);

		LineMetrics.resize(TextMetrics.lineCount);

		TextLayout->GetLineMetrics(&LineMetrics[0], TextMetrics.lineCount, &TextMetrics.lineCount);

		UINT32 Line = 0;
		UINT32 LinePosition = 0;
		UINT32 LineCount = static_cast<UINT32>(LineMetrics.size());
		for (; Line < LineCount; ++Line) {
			LinePosition += LineMetrics[Line].length;

			if (LinePosition > CaretStart) {
				break;
			}
		}

		CaretStart = CaretEnd;
		CaretEnd = LinePosition - 1;

		InSelecting = true;
		SelectMode = VEditorCaretSelectMode::Right;
	}
	void VEditorCaret::CaretSelectAll() {
		CaretStart = 0;
		CaretEnd   = CacheTargetPtr->size();

		InSelecting = true;
		SelectMode	= VEditorCaretSelectMode::Right;
	}
	void VEditorCaret::CaretPageUp() {
		CaretStart = 0;
		CaretEnd   = CaretStart;
	}
	void VEditorCaret::CaretPageEnd() {
		CaretStart = CacheTargetPtr->size();
		CaretEnd   = CaretStart;
	}
	void VEditorCaret::CaretTurnLeft() {
		if (CaretStart - 1 >= 0) {
			CaretStart -= 1;
			CaretEnd    = CaretStart;
		}
	}
	void VEditorCaret::CaretTurnRight() {
		if (CaretEnd + 1 <= CacheTargetPtr->size()) {
			CaretEnd  += 1;
			CaretStart = CaretEnd;
		}
	}

	void VEditorCaret::SetCaretByMousePosition(const int& X, const int& Y, IDWriteTextLayout* TextLayout) {
		BOOL					IsTrailingHit = FALSE;
		BOOL					IsInside	  = FALSE;
		DWRITE_HIT_TEST_METRICS HitTestMetrics;

		TextLayout->HitTestPoint(X, Y, &IsTrailingHit, &IsInside, &HitTestMetrics);

		CaretStart = HitTestMetrics.textPosition;
		CaretEnd   = HitTestMetrics.textPosition;
	}
	void VEditorCaret::SetCaretSelectionByMousePosition(const int& X, const int& Y, IDWriteTextLayout* TextLayout) {
		BOOL					IsTrailingHit = FALSE;
		BOOL					IsInside = FALSE;
		DWRITE_HIT_TEST_METRICS HitTestMetrics;

		TextLayout->HitTestPoint(X, Y, &IsTrailingHit, &IsInside, &HitTestMetrics);

		if (!InSelecting) {
			if (HitTestMetrics.textPosition > CaretEnd) {
				CaretStart = CaretEnd;

				InSelecting = true;

				SelectMode = VEditorCaretSelectMode::Right;

				CaretEnd = HitTestMetrics.textPosition;
			}
			else if (HitTestMetrics.textPosition < CaretStart) {
				InSelecting = true;

				SelectMode = VEditorCaretSelectMode::Left;

				CaretStart = HitTestMetrics.textPosition;
			}
			else {
				CaretEnd = HitTestMetrics.textPosition;
			}
		}
		else {
			if (HitTestMetrics.textPosition > CaretEnd) {
				if (SelectMode == VEditorCaretSelectMode::Left) {
					CaretStart = CaretEnd;

					SelectMode = VEditorCaretSelectMode::Right;

					CaretEnd = HitTestMetrics.textPosition;
				}
				else {
					CaretEnd = HitTestMetrics.textPosition;
				}
			}
			else if (HitTestMetrics.textPosition < CaretStart) {
				if (SelectMode == VEditorCaretSelectMode::Right) {
					CaretEnd = CaretStart;

					SelectMode = VEditorCaretSelectMode::Left;

					CaretStart = HitTestMetrics.textPosition;
				}
				else {
					CaretStart = HitTestMetrics.textPosition;
				}
			}
			else {
				if (SelectMode == VEditorCaretSelectMode::Right) {
					CaretEnd = HitTestMetrics.textPosition;
				}
				else {
					CaretStart = HitTestMetrics.textPosition;
				}
			}
		}
	}

	void VEditorCaret::SetValidCaretRange() {
		if (CaretEnd < CaretStart) {
			std::swap(CaretEnd, CaretStart);
		}
	}
	VPoint VEditorCaret::GetCaretPosition(IDWriteTextLayout* TextLayout) {
		DWRITE_HIT_TEST_METRICS CaretMetrics;

		FLOAT					CaretX = 0.f;
		FLOAT					CaretY = 0.f;

		if (!InSelecting) {
			TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &CaretMetrics);
		}
		else {
			switch (SelectMode) {
			case VEditorCaretSelectMode::Left: {
				TextLayout->HitTestTextPosition(CaretStart, FALSE, &CaretX, &CaretY, &CaretMetrics);

				break;
			}
			case VEditorCaretSelectMode::Right: {
				TextLayout->HitTestTextPosition(CaretEnd, FALSE, &CaretX, &CaretY, &CaretMetrics);

				break;
			}
			}
		}

		return VPoint(CaretMetrics.left, CaretMetrics.top);
	}
	DWRITE_TEXT_RANGE VEditorCaret::GetTextRange() {
		if (CaretEnd < CaretStart) {
			std::swap(CaretEnd, CaretStart);
		}

		UINT32 End   = CaretEnd;
		UINT32 Start = CaretStart;

		return DWRITE_TEXT_RANGE{ Start, End - Start };
	}

	VEditor::VEditor(VUIObject* Parent) : VAbstractButton(Parent), CaretTimer(this), ShowCaret(false) {
		Theme			= new VTextEditorTheme(*(static_cast<VTextEditorTheme*>(GetTargetTheme(VUIThemeType::VTextEditor))));
		Interpolator	= new VAnimationInterpolator(0.1, Theme->LocalTheme.AnimationInterpolatorType);

		Theme->LabelFont->SetParagraphAlignment(VFontParagraphAlignment::DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		FirstBackOff	= true;

		UsedComboKey	= false;

		OffsetX			= 5;
		YDelta			= 25;

		UserInOperating = false;

		Caret.CacheTargetPtr = &InEditingText;
		Caret.InSelecting	 = false;
		InMouseDragSelecting = false;

		ResetTextLayout();

		CaretTimer.Start(1000);
		CaretTimer.OnTime.Connect(this, &VEditor::ResetCaretStatus);
	}
	VEditor::VEditor(const int& Width, const int& Height, VUIObject* Parent) : VAbstractButton(Parent), CaretTimer(this), ShowCaret(false) {
		Theme			= new VTextEditorTheme(*(static_cast<VTextEditorTheme*>(GetTargetTheme(VUIThemeType::VTextEditor))));
		Interpolator	= new VAnimationInterpolator(0.1, Theme->LocalTheme.AnimationInterpolatorType);
		
		Theme->LabelFont->SetParagraphAlignment(VFontParagraphAlignment::DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		FirstBackOff	= true;

		UsedComboKey	= false;

		OffsetX			= 5;
		YDelta			= 25;

		UserInOperating = false;

		Caret.CacheTargetPtr = &InEditingText;
		Caret.InSelecting	 = false;
		InMouseDragSelecting = false;

		Resize(Width, Height);

		ResetTextLayout();

		CaretTimer.Start(500);
		CaretTimer.OnTime.Connect(this, &VEditor::ResetCaretStatus);
	}

	void VEditor::ResetCaretStatus() {
		if (UserInOperating) {
			ShowCaret = !ShowCaret;
		}
		else {
			ShowCaret = false;
		}

		CaretTimer.Start(500);

		Update();
	}
	void VEditor::ResetTextLayout() {
		LocalTextLayout.Reset();
		
		VDirectXWriteFactory.GetInstance()->CreateTextLayout(InEditingText.c_str(), InEditingText.size(), Theme->LabelFont->GetDXObject(),
			GetWidth() - Theme->LocalTheme.BorderThickness * 2, GetHeight() - Theme->LocalTheme.BorderThickness * 2,
			LocalTextLayout.GetAddressOf());

		for (auto& Effect : TextEffect) {
			LocalTextLayout->SetDrawingEffect(Effect.first, Effect.second);
		}

		Update();
	}

	void VEditor::SetPlaneText(const std::wstring& PlaneText) {
		InEditingText = PlaneText;

		ResetTextLayout();
	}

	void VEditor::OnPaint(VCanvasPainter* Painter) {
		Painter->BeginDraw();

		VSolidBrush TextBrush(Theme->LocalTheme.TextColor, CallWidgetGetRenderHandle());
		VSolidBrush BackgroundBrush(Theme->LocalTheme.BackgroundColor, CallWidgetGetRenderHandle());
		VPenBrush	SelectedBrush(Theme->OnSelectedColor, CallWidgetGetRenderHandle());
		VPenBrush	CaretBrush(Theme->CursorColor, CallWidgetGetRenderHandle(), 1.f);
		VPenBrush   BorderBrush(Theme->LocalTheme.BorderColor, CallWidgetGetRenderHandle(), Theme->LocalTheme.BorderThickness);

		LocalTextLayout->SetDrawingEffect(SelectedBrush.GetDxBrush(), Caret.GetTextRange());

		Painter->FillRoundedRectangle(VRect(Theme->LocalTheme.BorderThickness, Theme->LocalTheme.BorderThickness,
			GetWidth() - Theme->LocalTheme.BorderThickness, GetHeight() - Theme->LocalTheme.BorderThickness),
			Theme->LocalTheme.Radius, &BorderBrush, &BackgroundBrush);
		Painter->GetDXObject()->DrawTextLayout(D2D1::Point2F(OffsetX, OffsetY + Theme->LabelFont->GetTextSize()),
			LocalTextLayout.Get(), TextBrush.GetDxBrush());

		if (ShowCaret) {
			auto CaretPosition = Caret.GetCaretPosition(LocalTextLayout.Get());

			CaretPosition.Offset(OffsetX, OffsetY + Theme->LabelFont->GetTextSize() + 4);

			auto CaretEndPosition = CaretPosition;
			CaretEndPosition.Offset(0, Theme->LabelFont->GetTextSize() - 2);

			Painter->DrawLine(CaretPosition, CaretEndPosition, &CaretBrush);
		}

		Painter->EndDraw();

		ResetTextLayout();
	}

	void VEditor::LeftClickedDown() {
		InAnimation = true;
		UserInOperating = true;
		ShowCaret = true;

		OldTheme = Theme->LocalTheme;
		TargetTheme = Theme->ActiveTheme;

		Interpolator->Reset();
		AnimationFrameTimer.Start(0);

		CallWidgetSetFocusID(ObjectKernel.GlobalID);
		CallWidgetLockFocusID();

		Update();
	}
	void VEditor::GotMouseFocus() {
		InAnimation = true;

		OldTheme = Theme->LocalTheme;
		TargetTheme = Theme->OnHoverTheme;

		Interpolator->Reset();
		AnimationFrameTimer.Start(0);

		CallWidgetSetFocusID(ObjectKernel.GlobalID);
		CallWidgetLockFocusID();

		Update();
	}

	void VEditor::CheckFrame() {
		if (BackoffResetTimer.End() && time(NULL) - LastBackOffTime >= 1000) {
			FirstBackOff = true;
		}
		if (UserInOperating) {
			auto CaretPosition = Caret.GetCaretPosition(LocalTextLayout.Get());
			CallWidgetSetIME(GetX() + CaretPosition.X + 5, GetY() + CaretPosition.Y + Theme->LabelFont->GetTextSize() + 3);
		}
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
		}
		else if (InAnimation) {
			InAnimation = false;
		}
	}

	void VEditor::BackCharacter() {
		if (ClearSelectArea()) {
			return;
		}

		if (Caret.CaretStart - 1 >= 0) {
			InEditingText.erase(InEditingText.begin() + Caret.CaretStart - 1);
		}

		Caret.CaretTurnLeft();

		ResetTextLayout();
	}
	void VEditor::DeleteCharacter() {
		if (ClearSelectArea()) {
			return;
		}

		if (Caret.CaretStart < InEditingText.size()) {
			InEditingText.erase(InEditingText.begin() + Caret.CaretStart);
		}

		ResetTextLayout();
	}
	void VEditor::AddCharaceter(const wchar_t& Character) {
		ClearSelectArea();

		InEditingText.insert(InEditingText.begin() + Caret.CaretStart, Character);

		Caret.CaretTurnRight();

		ResetTextLayout();
	}

	bool VEditor::ClearSelectArea() {
		if (Caret.InSelecting) {
			Caret.InSelecting = false;

			InEditingText.erase(Caret.CaretStart, Caret.CaretEnd - Caret.CaretStart);

			Caret.CaretEnd = Caret.CaretStart;

			return true;
		}

		return false;
	}

	bool VEditor::IsASCIICharacter(const wchar_t& ASCIICode) {
		return !(ASCIICode >= 0 && ASCIICode <= 31 && ASCIICode == 127);
	}

	void VEditor::SetScroller() {
		auto CaretPosition = Caret.GetCaretPosition(LocalTextLayout.Get());

		if (CaretPosition.Y + Theme->LabelFont->GetTextSize() + 4 >= GetHeight() - OffsetY) {
			OffsetY = -(CaretPosition.Y + Theme->LabelFont->GetTextSize() + 4 - GetHeight()) - Theme->LabelFont->GetTextSize() - 4;
		}
		if (CaretPosition.Y < -OffsetY) {
			OffsetY = OffsetY - (OffsetY + CaretPosition.Y);
		}
	}
	int VEditor::GetMaxOffsetY() {
		DWRITE_TEXT_METRICS Metrics;

		LocalTextLayout->GetMetrics(&Metrics);

		return GetHeight() - Metrics.height - Theme->LabelFont->GetTextSize() - Theme->LocalTheme.BorderThickness - Theme->LocalTheme.Radius.X;
	}

	void VEditor::CopyClipboard() {
		DWRITE_TEXT_RANGE TextRange = Caret.GetTextRange();
		if (TextRange.length <= 0) {
			return;
		}

		if (OpenClipboard(0)) {
			if (EmptyClipboard()) {
				size_t	DataByteSize	= sizeof(wchar_t) * (TextRange.length + 1);
				HGLOBAL ClipboardHandle = GlobalAlloc(GMEM_DDESHARE | GMEM_ZEROINIT, DataByteSize);

				if (ClipboardHandle != NULL) {
					void* LockMemory = GlobalLock(ClipboardHandle);

					if (LockMemory != NULL) {
						const wchar_t* CString = InEditingText.c_str();

						memcpy(LockMemory, &CString[TextRange.startPosition], DataByteSize);

						GlobalUnlock(ClipboardHandle);
						if (SetClipboardData(CF_UNICODETEXT, ClipboardHandle) != NULL) {
							ClipboardHandle = NULL;
						}
					}

					GlobalFree(ClipboardHandle);
				}
			}
			CloseClipboard();
		}
	}
	void VEditor::WriteClipboard() {
		if (OpenClipboard(0)) {
			HGLOBAL ClipboardDataHandle = GetClipboardData(CF_UNICODETEXT);

			if (ClipboardDataHandle != NULL) {
				size_t MemoryByteSize  = GlobalSize(ClipboardDataHandle);
				void*  Memory		   = GlobalLock(ClipboardDataHandle);

				const wchar_t* CString = reinterpret_cast<const wchar_t*>(Memory);

				UINT StringCount = static_cast<UINT32>(wcsnlen(CString, MemoryByteSize / sizeof(wchar_t)));

				if (Memory != NULL) {
					InEditingText.insert(Caret.CaretStart, CString, StringCount);

					Caret.CaretStart += StringCount;
					Caret.CaretEnd = Caret.CaretStart;

					GlobalUnlock(ClipboardDataHandle);
				}
			}

			ResetTextLayout();

			CloseClipboard();
		}
	}
	VTextEditorTheme* VEditor::GetTheme() {
		return Theme;
	}

	void VEditor::OnMessage(VMessage* Message) {
		if (Message->GetType() == VMessageType::MouseClickedMessage) {
			auto MouseMessage = static_cast<VMouseClickedMessage*>(Message);

			if (MouseMessage->ClickedKey == Left && MouseMessage->ClickedMethod == Down &&
				!MouseMessage->MousePosition.InsideRectangle(GetRegion()) && CallWidgetGetFocusID() == ObjectKernel.GlobalID) {
				UserInOperating = false;
				ShowCaret = false;
				InAnimation = true;

				OldTheme = Theme->LocalTheme;
				TargetTheme = Theme->StaticTheme;

				Interpolator->Reset();
				AnimationFrameTimer.Start(0);

				Update();

				CallWidgetUnlockFocusID();
			}
			if (MouseMessage->ClickedKey == Left && MouseMessage->ClickedMethod == Up) {
				InMouseDragSelecting = false;
			}
			if (MouseMessage->ClickedKey == Left && MouseMessage->ClickedMethod == Down &&
				MouseMessage->MousePosition.InsideRectangle(GetRegion())) {
				auto X = MouseMessage->MousePosition.X;
				auto Y = MouseMessage->MousePosition.Y;

				X -= GetX();
				Y -= GetY();

				X -= OffsetX;
				
				Y -= Theme->LabelFont->GetTextSize();

				InMouseDragSelecting = true;

				if (!(GetAsyncKeyState(VK_SHIFT) & 0x8000)) {
					Caret.SetCaretByMousePosition(X, Y - OffsetY, LocalTextLayout.Get());
				}
				else {
					Caret.SetCaretSelectionByMousePosition(X, Y, LocalTextLayout.Get());

					Update();
				}
			}
		}
		if (Message->GetType() == VMessageType::MouseMoveMessage && InMouseDragSelecting) {
			auto MouseMoveMessage = static_cast<VMouseMoveMessage*>(Message);

			auto X = MouseMoveMessage->MousePosition.X;
			auto Y = MouseMoveMessage->MousePosition.Y;

			X -= GetX();
			Y -= GetY();

			X -= OffsetX;
			Y -= OffsetY;

			Y -= Theme->LabelFont->GetTextSize();

			Caret.SetCaretSelectionByMousePosition(X, Y, LocalTextLayout.Get());
		}
		if (Message->GetType() == VMessageType::IMECharMessage && UserInOperating) {
			auto IMECharMessage = static_cast<VIMECharMessage*>(Message);

			if (UsedComboKey) {
				UsedComboKey = false;

				return;
			}

			if (IMECharMessage->IMEChar != L'\b') {
				AddCharaceter(IMECharMessage->IMEChar);
			}
		}
		if (Message->GetType() == VMessageType::KeyClickedMessage && UserInOperating) {
			auto KeyMessage = static_cast<VKeyClickedMessage*>(Message);

			if (KeyMessage->KeyVKCode == VK_BACK && KeyMessage->KeyPrevDown && BackoffTimer.End()) {
				if (FirstBackOff) {
					FirstBackOff = false;

					LastBackOffTime = time(NULL);

					BackoffResetTimer.Start(1000);
					BackoffTimer.Start(250);
				}

				BackCharacter();
			}
			else if (KeyMessage->KeyVKCode == VK_DELETE) {
				DeleteCharacter();
			}
			else if (KeyMessage->KeyVKCode == VK_HOME) {
				if (!(GetAsyncKeyState(VK_SHIFT) & 0x8000)) {
					Caret.CaretTurnLineHead(LocalTextLayout.Get());
				}
				else if (KeyMessage->KeyPrevDown) {
					Caret.CaretSelectionTurnLineHead(LocalTextLayout.Get());
				}
			}
			else if (KeyMessage->KeyVKCode == VK_END && KeyMessage->KeyPrevDown){
				if (!(GetAsyncKeyState(VK_SHIFT) & 0x8000)) {
					Caret.CaretTurnLineEnd(LocalTextLayout.Get());
				}
				else if (KeyMessage->KeyPrevDown) {
					Caret.CaretSelectionTurnLineEnd(LocalTextLayout.Get());
				}
			}
			else if (KeyMessage->KeyVKCode == VK_PRIOR) {
				OffsetY = 0;
				Caret.CaretPageUp();
			}
			else if (KeyMessage->KeyVKCode == VK_NEXT) {
				Caret.CaretPageEnd();
			}
			else if (KeyMessage->KeyVKCode == 'A' && !KeyMessage->KeyPrevDown) {
				if ((GetAsyncKeyState(VK_CONTROL) & 0x8000)) {
					UsedComboKey = true;

					Caret.CaretSelectAll();
				}
			}
			else if (KeyMessage->KeyVKCode == 'C' && !KeyMessage->KeyPrevDown) {
				if ((GetAsyncKeyState(VK_CONTROL) & 0x8000)) {
					UsedComboKey = true;

					CopyClipboard();
				}
			}
			else if (KeyMessage->KeyVKCode == 'X' && !KeyMessage->KeyPrevDown) {
				if ((GetAsyncKeyState(VK_CONTROL) & 0x8000)) {
					UsedComboKey = true;

					ClearSelectArea();
					CopyClipboard();
				}
			}
			else if (KeyMessage->KeyVKCode == 'V' && !KeyMessage->KeyPrevDown) {
				if ((GetAsyncKeyState(VK_CONTROL) & 0x8000)) {
					UsedComboKey = true;

					ClearSelectArea();
					WriteClipboard();
				}
			}
			else if (KeyMessage->KeyVKCode == VK_UP && KeyMessage->KeyPrevDown) {
				if (!(GetAsyncKeyState(VK_SHIFT) & 0x8000)) {
					Caret.CaretTurnUp(LocalTextLayout.Get());
				}
				else {
					Caret.CaretSelectionTurnUp(LocalTextLayout.Get());
				}
			}
			else if (KeyMessage->KeyVKCode == VK_DOWN && KeyMessage->KeyPrevDown) {
				if (!(GetAsyncKeyState(VK_SHIFT) & 0x8000)) {
					Caret.CaretTurnDown(LocalTextLayout.Get());
				}
				else {
					Caret.CaretSelectionTurnDown(LocalTextLayout.Get());
				}
			}
			else if (KeyMessage->KeyVKCode == VK_RIGHT && KeyMessage->KeyPrevDown) {
				if (!(GetAsyncKeyState(VK_SHIFT) & 0x8000)) {
					Caret.CaretTurnRight();
				}
				else {
					Caret.CaretSelectionTurnRight();
				}
			}
			else if (KeyMessage->KeyVKCode == VK_LEFT && KeyMessage->KeyPrevDown) {
				if (!(GetAsyncKeyState(VK_SHIFT) & 0x8000)) {
					Caret.CaretTurnLeft();
				}
				else {
					Caret.CaretSelectionTurnLeft();
				}
			}
			
			CaretTimer.Start(500);
			ShowCaret = true;

			SetScroller();

			Update();
		}
		if (Message->GetType() == VMessageType::MouseWheelMessage) {
			auto MouseWheelMessage = static_cast<VMouseWheelMessage*>(Message);

			if (MouseWheelMessage->MousePosition.InsideRectangle(GetRegion())) {
				if (MouseWheelMessage->WheelValue < 0) {
					OffsetY -= YDelta;

					auto MaxOffset = GetMaxOffsetY();

					if (OffsetY < MaxOffset) {
						OffsetY = MaxOffset;
					}
				}
				else {
					OffsetY += YDelta;

					if (OffsetY > 0) {
						OffsetY = 0;
					}
				}
			}

			Update();
		}
	}
}

VLIB_END_NAMESPACE