// Copyright 2010-2015 Fabric Software Inc. All rights reserved.

#ifndef __UI_ValueEditor_Vec2ValueWidget__
#define __UI_ValueEditor_Vec2ValueWidget__

#include <QtGui/QLineEdit>

#include "ValueWidget.h"

namespace FabricUI
{

  namespace ValueEditor
  {
    class Vec2ValueWidget : public ValueWidget
    {
      Q_OBJECT

    public:

      Vec2ValueWidget(QString label, QWidget * parent);
      virtual ~Vec2ValueWidget();

      virtual void setValue(FabricCore::RTVal v);
      virtual void setEnabled(bool state);

      static TreeView::TreeEditorWidget * creator(QWidget * parent, TreeView::WidgetTreeItem * item);
      static bool canDisplay(TreeView::WidgetTreeItem * item);

    public slots:

      void onValueChangedInLineEdit();
      void onBeginInteraction();
      void onEndInteraction();

    private:

      QLineEdit * m_lineEditX;
      QLineEdit * m_lineEditY;
    };

  };

};

#endif // __UI_ValueEditor_Vec2ValueWidget__
