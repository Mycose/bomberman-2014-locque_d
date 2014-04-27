//
// XMLParser.cpp for bomberman in /home/moriss_c//projs/Bomberman/bomberman-2014-locque_d
// 
// Made by clement morissard
// Login   <moriss_c@epitech.net>
// 
// Started on  Thu Jun  2 13:05:06 2011 clement morissard
// Last update Fri Jun  3 12:59:37 2011 nicolas laille
//
#include <stdexcept>
#include "XMLParser.hh"

XMLParser::XMLParser()
  : xml()
{
}

XMLParser::XMLParser(std::string str)
  : xml(str)
{
}

XMLParser::~XMLParser()
{
}

void XMLParser::ResetMainPos()
{
  this->xml.ResetMainPos();
}

bool XMLParser::SetAttrib(MCD_CSTR szAttrib, MCD_CSTR szValue, int nFlags)
{
  if (this->xml.SetAttrib(szAttrib, szValue, nFlags) == false)
    throw std::runtime_error("setAttrib failed");
  return (true);
}

bool XMLParser::SetAttrib(MCD_CSTR szAttrib, int nValue, int nFlags)
{
  if (this->xml.SetAttrib(szAttrib, nValue, nFlags) == false)
    throw std::runtime_error("setAttrib failed");
  return (true);
}

bool XMLParser::FindElem(MCD_CSTR szName)
{
  if (this->xml.FindElem(szName) == false)
    throw std::runtime_error("findElem failed : " + static_cast<std::string>(szName));
  return (true);
}

bool XMLParser::IntoElem()
{
  if (this->xml.IntoElem() == false)
    throw std::runtime_error("intoElem failed");
  return (true);
}

bool XMLParser::AddElem(MCD_CSTR szName, MCD_CSTR szData, int nFlags)
{
  if (this->xml.AddElem(szName, szData, nFlags) == false)
    throw std::runtime_error("addElem failed");
  return (true);
}

bool XMLParser::AddElem(MCD_CSTR szName, int nValue, int nFlags)
{
  if (this->xml.AddElem(szName, nValue, nFlags) == false)
    throw std::runtime_error("addElem failed");
  return (true);
}

bool XMLParser::AddSubDoc(MCD_CSTR szSubDoc)
{
  if (this->xml.AddSubDoc(szSubDoc) == false)
    throw std::runtime_error("addSubDoc failed");
  return (true);
}

bool XMLParser::OutOfElem()
{
  if (this->xml.OutOfElem() == false)
    throw std::runtime_error("outOfElem failed");
  return (true);
}

MCD_STR XMLParser::GetData()
{
  std::string	str;

  str = this->xml.GetData();
  /*if (str.size() == 0)
    throw std::runtime_error("GetData failed");*/
  return (str);
}

MCD_STR XMLParser::GetSubDoc()
{
  std::string	str;

  str = this->xml.GetSubDoc();
  /*if (str.size() == 0)
    throw std::runtime_error("GetSubDoc failed");*/
  return (str);
}

MCD_STR XMLParser::GetAttrib(MCD_CSTR szAttrib) const
{
  std::string	str;

  str = this->xml.GetAttrib(szAttrib);
  if (str.size() == 0)
    throw std::runtime_error("GetAttrib failed");
  return (str);
}

bool XMLParser::Save(MCD_CSTR szFileName)
{
  if (this->xml.Save(szFileName) == false)
    throw std::runtime_error("save failed");
  return (true);
}

bool XMLParser::Load(MCD_CSTR szFileName)
{
  if (this->xml.Load(szFileName) == false)
    throw std::runtime_error("load failed " + this->xml.GetError());
  return (true);
}

MCD_STR& XMLParser::GetDoc()
{
  this->_str = this->xml.GetDoc();
  if (this->_str.size() == 0)
    throw std::runtime_error("GetAttrib failed");
  return (this->_str);
}

void	XMLParser::ResetPos(void)
{
  this->xml.ResetPos();
}
