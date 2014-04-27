//
// XMLParser.hh for bomberman in /home/moriss_c//projs/Bomberman/bomberman-2014-locque_d
// 
// Made by clement morissard
// Login   <moriss_c@epitech.net>
// 
// Started on  Thu Jun  2 12:52:17 2011 clement morissard
// Last update Fri Jun  3 12:58:54 2011 nicolas laille
//

#ifndef __XMLPARSER_HH__
# define __XMLPARSER_HH__

#include "Markup.h"

class XMLParser
{
public:
  XMLParser();
  XMLParser(std::string);
  ~XMLParser();

  void ResetMainPos();
  bool SetAttrib(MCD_CSTR szAttrib, MCD_CSTR szValue, int nFlags = 0);
  bool SetAttrib(MCD_CSTR szAttrib, int nValue, int nFlags = 0);
  bool FindElem(MCD_CSTR szName = NULL);
  bool IntoElem();
  bool AddElem(MCD_CSTR szName, MCD_CSTR szData = NULL, int nFlags = 0);
  bool AddElem(MCD_CSTR szName, int nValue, int nFlags = 0);
  bool AddSubDoc(MCD_CSTR szSubDoc);
  bool OutOfElem();
  MCD_STR GetData();
  MCD_STR GetSubDoc();
  MCD_STR GetAttrib(MCD_CSTR szAttrib) const;
  bool Save(MCD_CSTR szFileName);
  bool Load(MCD_CSTR szFileName);
  MCD_STR& GetDoc();
  void	ResetPos(void);
private:
  CMarkup	xml;
  std::string	_str;
};

#endif /* __XMLPARSER_HH__ */
