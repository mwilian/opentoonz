

#ifndef XSHROWVIEWER_H
#define XSHROWVIEWER_H

#include <QWidget>

// forward declaration
class XsheetViewer;
class QMenu;

namespace XsheetGUI
{

class DragTool;

//=============================================================================
// RowArea
//-----------------------------------------------------------------------------

//!La classe si occupa della visualizzazione dell'area che gestisce le righe.
class RowArea : public QWidget
{
	Q_OBJECT
	XsheetViewer *m_viewer;
	int m_xa;
	int m_row;
	bool m_showOnionToSet;

	// Play ranges
	int m_r0;
	int m_r1;

	QPoint m_pos;
	bool m_playRangeActiveInMousePress;
	int m_mousePressRow;
	QString m_tooltip;

	//panning by middle-drag
	bool m_isPanning;

	void drawRows(QPainter &p, int r0, int r1);
	void drawPlayRange(QPainter &p, int r0, int r1);
	void drawCurrentRowGadget(QPainter &p, int r0, int r1);
	void drawOnionSkinSelection(QPainter &p);

	DragTool *getDragTool() const;
	void setDragTool(DragTool *dragTool);

public:
#if QT_VERSION >= 0x050500
	RowArea(XsheetViewer *parent, Qt::WindowFlags flags = 0);
#else
	RowArea(XsheetViewer *parent, Qt::WFlags flags = 0);
#endif
	~RowArea();

protected:
	void paintEvent(QPaintEvent *);

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void contextMenuEvent(QContextMenuEvent *event);
	bool event(QEvent *event);

	void setMarker(int index);

protected slots:

	void onSetStartMarker();
	void onSetStopMarker();
	void onRemoveMarkers();

	//set both the from and to markers at the specified row
	void onPreviewThis();
};

} // namespace XsheetGUI;

#endif // XSHROWVIEWER_H
