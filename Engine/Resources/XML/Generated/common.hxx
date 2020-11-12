// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

#ifndef CXX_________ENGINE_RESOURCES_XML_SCHEMAS_COMMON_HXX
#define CXX_________ENGINE_RESOURCES_XML_SCHEMAS_COMMON_HXX

#ifndef XSD_CXX11
#define XSD_CXX11
#endif

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_TREE_USE_CHAR
#define XSD_CXX_TREE_USE_CHAR
#endif

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/types.hxx>

#include <xsd/cxx/xml/error-handler.hxx>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

#include <xsd/cxx/tree/parsing.hxx>
#include <xsd/cxx/tree/parsing/byte.hxx>
#include <xsd/cxx/tree/parsing/unsigned-byte.hxx>
#include <xsd/cxx/tree/parsing/short.hxx>
#include <xsd/cxx/tree/parsing/unsigned-short.hxx>
#include <xsd/cxx/tree/parsing/int.hxx>
#include <xsd/cxx/tree/parsing/unsigned-int.hxx>
#include <xsd/cxx/tree/parsing/long.hxx>
#include <xsd/cxx/tree/parsing/unsigned-long.hxx>
#include <xsd/cxx/tree/parsing/boolean.hxx>
#include <xsd/cxx/tree/parsing/float.hxx>
#include <xsd/cxx/tree/parsing/double.hxx>
#include <xsd/cxx/tree/parsing/decimal.hxx>

namespace xml_schema
{
  // anyType and anySimpleType.
  //
  typedef ::xsd::cxx::tree::type type;
  typedef ::xsd::cxx::tree::simple_type< char, type > simple_type;
  typedef ::xsd::cxx::tree::type container;

  // 8-bit
  //
  typedef signed char byte;
  typedef unsigned char unsigned_byte;

  // 16-bit
  //
  typedef short short_;
  typedef unsigned short unsigned_short;

  // 32-bit
  //
  typedef int int_;
  typedef unsigned int unsigned_int;

  // 64-bit
  //
  typedef long long long_;
  typedef unsigned long long unsigned_long;

  // Supposed to be arbitrary-length integral types.
  //
  typedef long long integer;
  typedef long long non_positive_integer;
  typedef unsigned long long non_negative_integer;
  typedef unsigned long long positive_integer;
  typedef long long negative_integer;

  // Boolean.
  //
  typedef bool boolean;

  // Floating-point types.
  //
  typedef float float_;
  typedef double double_;
  typedef double decimal;

  // String types.
  //
  typedef ::xsd::cxx::tree::string< char, simple_type > string;
  typedef ::xsd::cxx::tree::normalized_string< char, string > normalized_string;
  typedef ::xsd::cxx::tree::token< char, normalized_string > token;
  typedef ::xsd::cxx::tree::name< char, token > name;
  typedef ::xsd::cxx::tree::nmtoken< char, token > nmtoken;
  typedef ::xsd::cxx::tree::nmtokens< char, simple_type, nmtoken > nmtokens;
  typedef ::xsd::cxx::tree::ncname< char, name > ncname;
  typedef ::xsd::cxx::tree::language< char, token > language;

  // ID/IDREF.
  //
  typedef ::xsd::cxx::tree::id< char, ncname > id;
  typedef ::xsd::cxx::tree::idref< char, ncname, type > idref;
  typedef ::xsd::cxx::tree::idrefs< char, simple_type, idref > idrefs;

  // URI.
  //
  typedef ::xsd::cxx::tree::uri< char, simple_type > uri;

  // Qualified name.
  //
  typedef ::xsd::cxx::tree::qname< char, simple_type, uri, ncname > qname;

  // Binary.
  //
  typedef ::xsd::cxx::tree::buffer< char > buffer;
  typedef ::xsd::cxx::tree::base64_binary< char, simple_type > base64_binary;
  typedef ::xsd::cxx::tree::hex_binary< char, simple_type > hex_binary;

  // Date/time.
  //
  typedef ::xsd::cxx::tree::time_zone time_zone;
  typedef ::xsd::cxx::tree::date< char, simple_type > date;
  typedef ::xsd::cxx::tree::date_time< char, simple_type > date_time;
  typedef ::xsd::cxx::tree::duration< char, simple_type > duration;
  typedef ::xsd::cxx::tree::gday< char, simple_type > gday;
  typedef ::xsd::cxx::tree::gmonth< char, simple_type > gmonth;
  typedef ::xsd::cxx::tree::gmonth_day< char, simple_type > gmonth_day;
  typedef ::xsd::cxx::tree::gyear< char, simple_type > gyear;
  typedef ::xsd::cxx::tree::gyear_month< char, simple_type > gyear_month;
  typedef ::xsd::cxx::tree::time< char, simple_type > time;

  // Entity.
  //
  typedef ::xsd::cxx::tree::entity< char, ncname > entity;
  typedef ::xsd::cxx::tree::entities< char, simple_type, entity > entities;

  typedef ::xsd::cxx::tree::content_order content_order;
  // Flags and properties.
  //
  typedef ::xsd::cxx::tree::flags flags;
  typedef ::xsd::cxx::tree::properties< char > properties;

  // Parsing/serialization diagnostics.
  //
  typedef ::xsd::cxx::tree::severity severity;
  typedef ::xsd::cxx::tree::error< char > error;
  typedef ::xsd::cxx::tree::diagnostics< char > diagnostics;

  // Exceptions.
  //
  typedef ::xsd::cxx::tree::exception< char > exception;
  typedef ::xsd::cxx::tree::bounds< char > bounds;
  typedef ::xsd::cxx::tree::duplicate_id< char > duplicate_id;
  typedef ::xsd::cxx::tree::parsing< char > parsing;
  typedef ::xsd::cxx::tree::expected_element< char > expected_element;
  typedef ::xsd::cxx::tree::unexpected_element< char > unexpected_element;
  typedef ::xsd::cxx::tree::expected_attribute< char > expected_attribute;
  typedef ::xsd::cxx::tree::unexpected_enumerator< char > unexpected_enumerator;
  typedef ::xsd::cxx::tree::expected_text_content< char > expected_text_content;
  typedef ::xsd::cxx::tree::no_prefix_mapping< char > no_prefix_mapping;

  // Error handler callback interface.
  //
  typedef ::xsd::cxx::xml::error_handler< char > error_handler;

  // DOM interaction.
  //
  namespace dom
  {
    // Automatic pointer for DOMDocument.
    //
    using ::xsd::cxx::xml::dom::unique_ptr;

#ifndef XSD_CXX_TREE_TREE_NODE_KEY__XML_SCHEMA
#define XSD_CXX_TREE_TREE_NODE_KEY__XML_SCHEMA
    // DOM user data key for back pointers to tree nodes.
    //
    const XMLCh* const tree_node_key = ::xsd::cxx::tree::user_data_keys::node;
#endif
  }
}

// Forward declarations.
//
class repeatType;
class assets;
class events;
class collider;
class position;
class base;
class onEnter;
class onLeave;
class onAttacked;
class onDestroyed;
class onAttack;
class size;

#include <memory>    // ::std::unique_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search
#include <utility>   // std::move

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

class repeatType: public ::xml_schema::string
{
  public:
  enum value
  {
    no_repeat,
    repeat,
    repeat_y,
    repeat_x
  };

  repeatType (value v);

  repeatType (const char* v);

  repeatType (const ::std::string& v);

  repeatType (const ::xml_schema::string& v);

  repeatType (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

  repeatType (const ::xercesc::DOMAttr& a,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

  repeatType (const ::std::string& s,
              const ::xercesc::DOMElement* e,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

  repeatType (const repeatType& x,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

  virtual repeatType*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  repeatType&
  operator= (value v);

  virtual
  operator value () const
  {
    return _xsd_repeatType_convert ();
  }

  protected:
  value
  _xsd_repeatType_convert () const;

  public:
  static const char* const _xsd_repeatType_literals_[4];
  static const value _xsd_repeatType_indexes_[4];
};

class assets: public ::xml_schema::type
{
  public:
  // base
  //
  typedef ::base base_type;
  typedef ::xsd::cxx::tree::traits< base_type, char > base_traits;

  const base_type&
  base () const;

  base_type&
  base ();

  void
  base (const base_type& x);

  void
  base (::std::unique_ptr< base_type > p);

  // Constructors.
  //
  assets (const base_type&);

  assets (::std::unique_ptr< base_type >);

  assets (const ::xercesc::DOMElement& e,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

  assets (const assets& x,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

  virtual assets*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  assets&
  operator= (const assets& x);

  virtual 
  ~assets ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  ::xsd::cxx::tree::one< base_type > base_;
};

class events: public ::xml_schema::type
{
  public:
  // onEnter
  //
  typedef ::onEnter onEnter_type;
  typedef ::xsd::cxx::tree::optional< onEnter_type > onEnter_optional;
  typedef ::xsd::cxx::tree::traits< onEnter_type, char > onEnter_traits;

  const onEnter_optional&
  onEnter () const;

  onEnter_optional&
  onEnter ();

  void
  onEnter (const onEnter_type& x);

  void
  onEnter (const onEnter_optional& x);

  void
  onEnter (::std::unique_ptr< onEnter_type > p);

  // onLeave
  //
  typedef ::onLeave onLeave_type;
  typedef ::xsd::cxx::tree::optional< onLeave_type > onLeave_optional;
  typedef ::xsd::cxx::tree::traits< onLeave_type, char > onLeave_traits;

  const onLeave_optional&
  onLeave () const;

  onLeave_optional&
  onLeave ();

  void
  onLeave (const onLeave_type& x);

  void
  onLeave (const onLeave_optional& x);

  void
  onLeave (::std::unique_ptr< onLeave_type > p);

  // onAttacked
  //
  typedef ::onAttacked onAttacked_type;
  typedef ::xsd::cxx::tree::optional< onAttacked_type > onAttacked_optional;
  typedef ::xsd::cxx::tree::traits< onAttacked_type, char > onAttacked_traits;

  const onAttacked_optional&
  onAttacked () const;

  onAttacked_optional&
  onAttacked ();

  void
  onAttacked (const onAttacked_type& x);

  void
  onAttacked (const onAttacked_optional& x);

  void
  onAttacked (::std::unique_ptr< onAttacked_type > p);

  // onDestroyed
  //
  typedef ::onDestroyed onDestroyed_type;
  typedef ::xsd::cxx::tree::optional< onDestroyed_type > onDestroyed_optional;
  typedef ::xsd::cxx::tree::traits< onDestroyed_type, char > onDestroyed_traits;

  const onDestroyed_optional&
  onDestroyed () const;

  onDestroyed_optional&
  onDestroyed ();

  void
  onDestroyed (const onDestroyed_type& x);

  void
  onDestroyed (const onDestroyed_optional& x);

  void
  onDestroyed (::std::unique_ptr< onDestroyed_type > p);

  // onAttack
  //
  typedef ::onAttack onAttack_type;
  typedef ::xsd::cxx::tree::optional< onAttack_type > onAttack_optional;
  typedef ::xsd::cxx::tree::traits< onAttack_type, char > onAttack_traits;

  const onAttack_optional&
  onAttack () const;

  onAttack_optional&
  onAttack ();

  void
  onAttack (const onAttack_type& x);

  void
  onAttack (const onAttack_optional& x);

  void
  onAttack (::std::unique_ptr< onAttack_type > p);

  // Constructors.
  //
  events ();

  events (const ::xercesc::DOMElement& e,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

  events (const events& x,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

  virtual events*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  events&
  operator= (const events& x);

  virtual 
  ~events ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  onEnter_optional onEnter_;
  onLeave_optional onLeave_;
  onAttacked_optional onAttacked_;
  onDestroyed_optional onDestroyed_;
  onAttack_optional onAttack_;
};

class collider: public ::xml_schema::type
{
  public:
  // size
  //
  typedef ::size size_type;
  typedef ::xsd::cxx::tree::traits< size_type, char > size_traits;

  const size_type&
  size () const;

  size_type&
  size ();

  void
  size (const size_type& x);

  void
  size (::std::unique_ptr< size_type > p);

  // hasCollision
  //
  typedef ::xml_schema::boolean hasCollision_type;
  typedef ::xsd::cxx::tree::traits< hasCollision_type, char > hasCollision_traits;

  const hasCollision_type&
  hasCollision () const;

  hasCollision_type&
  hasCollision ();

  void
  hasCollision (const hasCollision_type& x);

  // Constructors.
  //
  collider (const size_type&,
            const hasCollision_type&);

  collider (::std::unique_ptr< size_type >,
            const hasCollision_type&);

  collider (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

  collider (const collider& x,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

  virtual collider*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  collider&
  operator= (const collider& x);

  virtual 
  ~collider ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  ::xsd::cxx::tree::one< size_type > size_;
  ::xsd::cxx::tree::one< hasCollision_type > hasCollision_;
};

class position: public ::xml_schema::type
{
  public:
  // x
  //
  typedef ::xml_schema::integer x_type;
  typedef ::xsd::cxx::tree::traits< x_type, char > x_traits;

  const x_type&
  x () const;

  x_type&
  x ();

  void
  x (const x_type& x);

  // y
  //
  typedef ::xml_schema::integer y_type;
  typedef ::xsd::cxx::tree::traits< y_type, char > y_traits;

  const y_type&
  y () const;

  y_type&
  y ();

  void
  y (const y_type& x);

  // Constructors.
  //
  position (const x_type&,
            const y_type&);

  position (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

  position (const position& x,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

  virtual position*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  position&
  operator= (const position& x);

  virtual 
  ~position ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  ::xsd::cxx::tree::one< x_type > x_;
  ::xsd::cxx::tree::one< y_type > y_;
};

class base: public ::xml_schema::type
{
  public:
  // file
  //
  typedef ::xml_schema::uri file_type;
  typedef ::xsd::cxx::tree::traits< file_type, char > file_traits;

  const file_type&
  file () const;

  file_type&
  file ();

  void
  file (const file_type& x);

  void
  file (::std::unique_ptr< file_type > p);

  // repeat
  //
  typedef ::repeatType repeat_type;
  typedef ::xsd::cxx::tree::traits< repeat_type, char > repeat_traits;

  const repeat_type&
  repeat () const;

  repeat_type&
  repeat ();

  void
  repeat (const repeat_type& x);

  void
  repeat (::std::unique_ptr< repeat_type > p);

  static const repeat_type&
  repeat_default_value ();

  // Constructors.
  //
  base (const file_type&);

  base (const ::xercesc::DOMElement& e,
        ::xml_schema::flags f = 0,
        ::xml_schema::container* c = 0);

  base (const base& x,
        ::xml_schema::flags f = 0,
        ::xml_schema::container* c = 0);

  virtual base*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  base&
  operator= (const base& x);

  virtual 
  ~base ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  ::xsd::cxx::tree::one< file_type > file_;
  ::xsd::cxx::tree::one< repeat_type > repeat_;
  static const repeat_type repeat_default_value_;
};

class onEnter: public ::xml_schema::type
{
  public:
  // soundAction
  //
  typedef ::xml_schema::uri soundAction_type;
  typedef ::xsd::cxx::tree::optional< soundAction_type > soundAction_optional;
  typedef ::xsd::cxx::tree::traits< soundAction_type, char > soundAction_traits;

  const soundAction_optional&
  soundAction () const;

  soundAction_optional&
  soundAction ();

  void
  soundAction (const soundAction_type& x);

  void
  soundAction (const soundAction_optional& x);

  void
  soundAction (::std::unique_ptr< soundAction_type > p);

  // loadAction
  //
  typedef ::xml_schema::uri loadAction_type;
  typedef ::xsd::cxx::tree::optional< loadAction_type > loadAction_optional;
  typedef ::xsd::cxx::tree::traits< loadAction_type, char > loadAction_traits;

  const loadAction_optional&
  loadAction () const;

  loadAction_optional&
  loadAction ();

  void
  loadAction (const loadAction_type& x);

  void
  loadAction (const loadAction_optional& x);

  void
  loadAction (::std::unique_ptr< loadAction_type > p);

  // Constructors.
  //
  onEnter ();

  onEnter (const ::xercesc::DOMElement& e,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

  onEnter (const onEnter& x,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

  virtual onEnter*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  onEnter&
  operator= (const onEnter& x);

  virtual 
  ~onEnter ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  soundAction_optional soundAction_;
  loadAction_optional loadAction_;
};

class onLeave: public ::xml_schema::type
{
  public:
  // soundAction
  //
  typedef ::xml_schema::uri soundAction_type;
  typedef ::xsd::cxx::tree::optional< soundAction_type > soundAction_optional;
  typedef ::xsd::cxx::tree::traits< soundAction_type, char > soundAction_traits;

  const soundAction_optional&
  soundAction () const;

  soundAction_optional&
  soundAction ();

  void
  soundAction (const soundAction_type& x);

  void
  soundAction (const soundAction_optional& x);

  void
  soundAction (::std::unique_ptr< soundAction_type > p);

  // loadAction
  //
  typedef ::xml_schema::uri loadAction_type;
  typedef ::xsd::cxx::tree::optional< loadAction_type > loadAction_optional;
  typedef ::xsd::cxx::tree::traits< loadAction_type, char > loadAction_traits;

  const loadAction_optional&
  loadAction () const;

  loadAction_optional&
  loadAction ();

  void
  loadAction (const loadAction_type& x);

  void
  loadAction (const loadAction_optional& x);

  void
  loadAction (::std::unique_ptr< loadAction_type > p);

  // Constructors.
  //
  onLeave ();

  onLeave (const ::xercesc::DOMElement& e,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

  onLeave (const onLeave& x,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

  virtual onLeave*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  onLeave&
  operator= (const onLeave& x);

  virtual 
  ~onLeave ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  soundAction_optional soundAction_;
  loadAction_optional loadAction_;
};

class onAttacked: public ::xml_schema::type
{
  public:
  // soundAction
  //
  typedef ::xml_schema::uri soundAction_type;
  typedef ::xsd::cxx::tree::optional< soundAction_type > soundAction_optional;
  typedef ::xsd::cxx::tree::traits< soundAction_type, char > soundAction_traits;

  const soundAction_optional&
  soundAction () const;

  soundAction_optional&
  soundAction ();

  void
  soundAction (const soundAction_type& x);

  void
  soundAction (const soundAction_optional& x);

  void
  soundAction (::std::unique_ptr< soundAction_type > p);

  // loadAction
  //
  typedef ::xml_schema::uri loadAction_type;
  typedef ::xsd::cxx::tree::optional< loadAction_type > loadAction_optional;
  typedef ::xsd::cxx::tree::traits< loadAction_type, char > loadAction_traits;

  const loadAction_optional&
  loadAction () const;

  loadAction_optional&
  loadAction ();

  void
  loadAction (const loadAction_type& x);

  void
  loadAction (const loadAction_optional& x);

  void
  loadAction (::std::unique_ptr< loadAction_type > p);

  // Constructors.
  //
  onAttacked ();

  onAttacked (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

  onAttacked (const onAttacked& x,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

  virtual onAttacked*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  onAttacked&
  operator= (const onAttacked& x);

  virtual 
  ~onAttacked ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  soundAction_optional soundAction_;
  loadAction_optional loadAction_;
};

class onDestroyed: public ::xml_schema::type
{
  public:
  // soundAction
  //
  typedef ::xml_schema::uri soundAction_type;
  typedef ::xsd::cxx::tree::optional< soundAction_type > soundAction_optional;
  typedef ::xsd::cxx::tree::traits< soundAction_type, char > soundAction_traits;

  const soundAction_optional&
  soundAction () const;

  soundAction_optional&
  soundAction ();

  void
  soundAction (const soundAction_type& x);

  void
  soundAction (const soundAction_optional& x);

  void
  soundAction (::std::unique_ptr< soundAction_type > p);

  // loadAction
  //
  typedef ::xml_schema::uri loadAction_type;
  typedef ::xsd::cxx::tree::optional< loadAction_type > loadAction_optional;
  typedef ::xsd::cxx::tree::traits< loadAction_type, char > loadAction_traits;

  const loadAction_optional&
  loadAction () const;

  loadAction_optional&
  loadAction ();

  void
  loadAction (const loadAction_type& x);

  void
  loadAction (const loadAction_optional& x);

  void
  loadAction (::std::unique_ptr< loadAction_type > p);

  // Constructors.
  //
  onDestroyed ();

  onDestroyed (const ::xercesc::DOMElement& e,
               ::xml_schema::flags f = 0,
               ::xml_schema::container* c = 0);

  onDestroyed (const onDestroyed& x,
               ::xml_schema::flags f = 0,
               ::xml_schema::container* c = 0);

  virtual onDestroyed*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  onDestroyed&
  operator= (const onDestroyed& x);

  virtual 
  ~onDestroyed ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  soundAction_optional soundAction_;
  loadAction_optional loadAction_;
};

class onAttack: public ::xml_schema::type
{
  public:
  // soundAction
  //
  typedef ::xml_schema::uri soundAction_type;
  typedef ::xsd::cxx::tree::optional< soundAction_type > soundAction_optional;
  typedef ::xsd::cxx::tree::traits< soundAction_type, char > soundAction_traits;

  const soundAction_optional&
  soundAction () const;

  soundAction_optional&
  soundAction ();

  void
  soundAction (const soundAction_type& x);

  void
  soundAction (const soundAction_optional& x);

  void
  soundAction (::std::unique_ptr< soundAction_type > p);

  // loadAction
  //
  typedef ::xml_schema::uri loadAction_type;
  typedef ::xsd::cxx::tree::optional< loadAction_type > loadAction_optional;
  typedef ::xsd::cxx::tree::traits< loadAction_type, char > loadAction_traits;

  const loadAction_optional&
  loadAction () const;

  loadAction_optional&
  loadAction ();

  void
  loadAction (const loadAction_type& x);

  void
  loadAction (const loadAction_optional& x);

  void
  loadAction (::std::unique_ptr< loadAction_type > p);

  // Constructors.
  //
  onAttack ();

  onAttack (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

  onAttack (const onAttack& x,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

  virtual onAttack*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  onAttack&
  operator= (const onAttack& x);

  virtual 
  ~onAttack ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  soundAction_optional soundAction_;
  loadAction_optional loadAction_;
};

class size: public ::xml_schema::type
{
  public:
  // width
  //
  typedef ::xml_schema::int_ width_type;
  typedef ::xsd::cxx::tree::traits< width_type, char > width_traits;

  const width_type&
  width () const;

  width_type&
  width ();

  void
  width (const width_type& x);

  // height
  //
  typedef ::xml_schema::int_ height_type;
  typedef ::xsd::cxx::tree::traits< height_type, char > height_traits;

  const height_type&
  height () const;

  height_type&
  height ();

  void
  height (const height_type& x);

  // Constructors.
  //
  size (const width_type&,
        const height_type&);

  size (const ::xercesc::DOMElement& e,
        ::xml_schema::flags f = 0,
        ::xml_schema::container* c = 0);

  size (const size& x,
        ::xml_schema::flags f = 0,
        ::xml_schema::container* c = 0);

  virtual size*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  size&
  operator= (const size& x);

  virtual 
  ~size ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  ::xsd::cxx::tree::one< width_type > width_;
  ::xsd::cxx::tree::one< height_type > height_;
};

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

// Parse a URI or a local file.
//

::std::unique_ptr< ::assets >
assets_ (const ::std::string& uri,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::assets >
assets_ (const ::std::string& uri,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::assets >
assets_ (const ::std::string& uri,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse std::istream.
//

::std::unique_ptr< ::assets >
assets_ (::std::istream& is,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::assets >
assets_ (::std::istream& is,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::assets >
assets_ (::std::istream& is,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::assets >
assets_ (::std::istream& is,
         const ::std::string& id,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::assets >
assets_ (::std::istream& is,
         const ::std::string& id,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::assets >
assets_ (::std::istream& is,
         const ::std::string& id,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::InputSource.
//

::std::unique_ptr< ::assets >
assets_ (::xercesc::InputSource& is,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::assets >
assets_ (::xercesc::InputSource& is,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::assets >
assets_ (::xercesc::InputSource& is,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::DOMDocument.
//

::std::unique_ptr< ::assets >
assets_ (const ::xercesc::DOMDocument& d,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::assets >
assets_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse a URI or a local file.
//

::std::unique_ptr< ::events >
events_ (const ::std::string& uri,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::events >
events_ (const ::std::string& uri,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::events >
events_ (const ::std::string& uri,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse std::istream.
//

::std::unique_ptr< ::events >
events_ (::std::istream& is,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::events >
events_ (::std::istream& is,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::events >
events_ (::std::istream& is,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::events >
events_ (::std::istream& is,
         const ::std::string& id,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::events >
events_ (::std::istream& is,
         const ::std::string& id,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::events >
events_ (::std::istream& is,
         const ::std::string& id,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::InputSource.
//

::std::unique_ptr< ::events >
events_ (::xercesc::InputSource& is,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::events >
events_ (::xercesc::InputSource& is,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::events >
events_ (::xercesc::InputSource& is,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::DOMDocument.
//

::std::unique_ptr< ::events >
events_ (const ::xercesc::DOMDocument& d,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::events >
events_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse a URI or a local file.
//

::std::unique_ptr< ::collider >
collider_ (const ::std::string& uri,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::collider >
collider_ (const ::std::string& uri,
           ::xml_schema::error_handler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::collider >
collider_ (const ::std::string& uri,
           ::xercesc::DOMErrorHandler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse std::istream.
//

::std::unique_ptr< ::collider >
collider_ (::std::istream& is,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::collider >
collider_ (::std::istream& is,
           ::xml_schema::error_handler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::collider >
collider_ (::std::istream& is,
           ::xercesc::DOMErrorHandler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::collider >
collider_ (::std::istream& is,
           const ::std::string& id,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::collider >
collider_ (::std::istream& is,
           const ::std::string& id,
           ::xml_schema::error_handler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::collider >
collider_ (::std::istream& is,
           const ::std::string& id,
           ::xercesc::DOMErrorHandler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::InputSource.
//

::std::unique_ptr< ::collider >
collider_ (::xercesc::InputSource& is,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::collider >
collider_ (::xercesc::InputSource& is,
           ::xml_schema::error_handler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::collider >
collider_ (::xercesc::InputSource& is,
           ::xercesc::DOMErrorHandler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::DOMDocument.
//

::std::unique_ptr< ::collider >
collider_ (const ::xercesc::DOMDocument& d,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::collider >
collider_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse a URI or a local file.
//

::std::unique_ptr< ::position >
position_ (const ::std::string& uri,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::position >
position_ (const ::std::string& uri,
           ::xml_schema::error_handler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::position >
position_ (const ::std::string& uri,
           ::xercesc::DOMErrorHandler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse std::istream.
//

::std::unique_ptr< ::position >
position_ (::std::istream& is,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::position >
position_ (::std::istream& is,
           ::xml_schema::error_handler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::position >
position_ (::std::istream& is,
           ::xercesc::DOMErrorHandler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::position >
position_ (::std::istream& is,
           const ::std::string& id,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::position >
position_ (::std::istream& is,
           const ::std::string& id,
           ::xml_schema::error_handler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::position >
position_ (::std::istream& is,
           const ::std::string& id,
           ::xercesc::DOMErrorHandler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::InputSource.
//

::std::unique_ptr< ::position >
position_ (::xercesc::InputSource& is,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::position >
position_ (::xercesc::InputSource& is,
           ::xml_schema::error_handler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::position >
position_ (::xercesc::InputSource& is,
           ::xercesc::DOMErrorHandler& eh,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::DOMDocument.
//

::std::unique_ptr< ::position >
position_ (const ::xercesc::DOMDocument& d,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::unique_ptr< ::position >
position_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
           ::xml_schema::flags f = 0,
           const ::xml_schema::properties& p = ::xml_schema::properties ());

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX_________ENGINE_RESOURCES_XML_SCHEMAS_COMMON_HXX