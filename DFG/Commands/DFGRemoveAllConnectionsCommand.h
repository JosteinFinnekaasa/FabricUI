// Copyright 2010-2015 Fabric Software Inc. All rights reserved.

#ifndef __UI_DFG_DFGRemoveAllConnectionsCommand__
#define __UI_DFG_DFGRemoveAllConnectionsCommand__

#include "DFGCommand.h"
#include <GraphView/Port.h>

#include "../DFGController.h"

namespace FabricUI
{

  namespace DFG
  {
    class DFGRemoveAllConnectionsCommand: public DFGCommand
    {
    public:

      DFGRemoveAllConnectionsCommand(DFGController * controller, const char * path, bool asPin);

      virtual const char * getName() const { return "dfgRemoveAllConnections"; }
      virtual const char * getShortDesc() const { return "Removes all connection for an endpoint in a graph."; }
      virtual const char * getFullDesc() const { return "Removes all connection for an endpoint in a graph."; }

      const char * getPath() const;
      bool isPin() const;

    protected:
      
      virtual bool invoke();
      virtual bool undo();
      virtual bool redo();

    private:

      bool m_isPin;
      std::string m_path;
      std::string m_nodePath;
      std::string m_pinTitle;

    };

  };

};

#endif // __UI_DFG_DFGRemoveAllConnectionsCommand__
