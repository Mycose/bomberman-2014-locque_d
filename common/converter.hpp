//
// avm_valconverter.hh for vm in /home/le_b//projects/tek2/cpp/abstractvm
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed Feb 16 10:32:21 2011 pierre le
// Last update Thu May 12 13:12:18 2011 nicolas laille
//

#ifndef		__AVM_VALCONVERTER_HH__
# define	__AVM_VALCONVERTER_HH__

# include	<sstream>


template	<typename outputType>
class		Convert
{
public:
  static outputType	convertToType(const std::string &in)
  {
    std::istringstream	temp(in.c_str());
    outputType		res;

    temp >> res;
    return (res);
  }

  static const std::string	convertToType(const outputType& in)
  {
    std::stringstream	temp;
    std::string		res;

    temp << in;
    temp >> res;
    return (res);
  }
};


#endif		// !__AVM_VALCONVERTER_HH__
