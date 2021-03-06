// Copyright 2010-2015 Fabric Software Inc. All rights reserved.

#ifndef __UI_GraphView_AddPinCommand__
#define __UI_GraphView_AddPinCommand__

#include "../Controller.h"
#include "ControllerCommand.h"

namespace FabricUI
{

  namespace GraphView
  {
    class AddPinCommand : public ControllerCommand
    {
    public:

      AddPinCommand(Controller * controller, Node * node, QString name, PortType pType, QColor color, QString dataType);
      virtual ~AddPinCommand();

      virtual const char * getName() const { return "AddPin"; }
      virtual const char * getShortDesc() const { return "Adds a pin to a node in the graph."; }
      virtual const char * getFullDesc() const { return "Adds a pin to a node in the graph using a given a pin name, type, color, label and datatype."; }

      virtual Node * getNode();
      virtual Pin * getPin();

    protected:
      
      virtual bool invoke();
      virtual bool undo();

      QString m_path;
      QString m_name;
      PortType m_pType;
      QColor m_color;
      QString m_dataType;

    };

  };

};

#endif // __UI_GraphView_AddPinCommand__
