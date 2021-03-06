// Copyright 2010-2015 Fabric Software Inc. All rights reserved.

#include "DFGSetDefaultValueCommand.h"

#include <DFGWrapper/KLTypeDesc.h>
#include <GraphView/Graph.h>

using namespace FabricServices;
using namespace FabricUI;
using namespace FabricUI::DFG;

DFGSetDefaultValueCommand::DFGSetDefaultValueCommand(DFGController * controller, QString path, FabricCore::RTVal value)
: DFGCommand(controller)
{
  m_path = path.toUtf8().constData();
  m_value = value;
  m_dataType = m_value.getTypeName().getStringCString();
  m_json = m_value.getJSON().getStringCString();
}

bool DFGSetDefaultValueCommand::invoke()
{
  if(!m_value.isValid())
    return false;

  DFGView * view = (DFGView *)((DFGController*)controller())->getView();
  DFGWrapper::GraphExecutablePtr graph = view->getGraph();
  DFGWrapper::PortPtr port = DFGWrapper::Port::Create(
    graph->getWrappedCoreBinding(), graph->getWrappedCoreExec(), graph->getExecPath(), m_path.c_str());
  if(!port)
    return false;
  if(port->isNodePort())
  {
    DFGWrapper::NodePortPtr nodePort = DFGWrapper::NodePortPtr::StaticCast(port);
    nodePort->setDefaultValue(m_value);
  }
  else
  {
    DFGWrapper::ExecPortPtr execPort = DFGWrapper::ExecPortPtr::StaticCast(port);
    execPort->setDefaultValue(m_value);
  }
  return true;
}

bool DFGSetDefaultValueCommand::undo()
{
  DFGController * ctrl = (DFGController*)controller();
  return ctrl->getHost()->maybeUndo();  
}

bool DFGSetDefaultValueCommand::redo()
{
  DFGController * ctrl = (DFGController*)controller();
  return ctrl->getHost()->maybeRedo();  
}

const char * DFGSetDefaultValueCommand::getPath() const
{
  return m_path.c_str();
}

const char * DFGSetDefaultValueCommand::getDataType() const
{
  return m_dataType.c_str();
}

const char * DFGSetDefaultValueCommand::getJSON() const
{
  return m_json.c_str();
}

FabricCore::RTVal DFGSetDefaultValueCommand::getValue() const
{
  return m_value;
}
