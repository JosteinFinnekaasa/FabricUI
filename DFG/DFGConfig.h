// Copyright 2010-2015 Fabric Software Inc. All rights reserved.

#ifndef __UI_DFG_DFGConfig__
#define __UI_DFG_DFGConfig__

#include <QtGui/QColor>
#include <QtGui/QFont>
#include <QtGui/QTextCharFormat>
#include <string>
#include <map>
#include <KLEditor/EditorConfig.h>
#include <GraphView/GraphConfig.h>

#include <DFGWrapper/ExecPort.h>

namespace FabricUI
{

  namespace DFG
  {

    struct DFGConfig
    {
      QColor defaultBackgroundColor;
      QColor defaultWindowColor;
      QFont defaultFont;
      QColor defaultFontColor;
      QFont fixedFont;
      QFont logFont;
      QColor searchBackgroundColor;
      QColor searchHighlightColor;
      QColor searchFontColor;

      std::map<std::string, QColor> colorForDataType;

      KLEditor::EditorConfig klEditorConfig;
      GraphView::GraphConfig graphConfig;

      DFGConfig();

      void registerDataTypeColor(const std::string & dataType, QColor color);
      QColor getColorForDataType(const std::string & dataType, FabricServices::DFGWrapper::ExecPortPtr port = NULL);
    };

  };

};

#endif // __UI_DFG_DFGConfig__
