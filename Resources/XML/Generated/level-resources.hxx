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

#ifndef RESOURCES_XML_SCHEMAS_LEVEL_RESOURCES_HXX
#define RESOURCES_XML_SCHEMAS_LEVEL_RESOURCES_HXX

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
namespace LevelResources
{
  class floatCap;
  class level;
  class object;
  class components;
  class worldPositionComponent;
  class physicsComponent;
}


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

#include "common.hxx"

namespace LevelResources
{
  class floatCap: public ::xsd::cxx::tree::fundamental_base< ::xml_schema::float_, char, ::xml_schema::simple_type >
  {
    public:
    // Constructors.
    //
    floatCap (const ::xml_schema::float_&);

    floatCap (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    floatCap (const ::xercesc::DOMAttr& a,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    floatCap (const ::std::string& s,
              const ::xercesc::DOMElement* e,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    floatCap (const floatCap& x,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    virtual floatCap*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~floatCap ();
  };

  class level: public ::xml_schema::type
  {
    public:
    // object
    //
    typedef ::LevelResources::object object_type;
    typedef ::xsd::cxx::tree::sequence< object_type > object_sequence;
    typedef object_sequence::iterator object_iterator;
    typedef object_sequence::const_iterator object_const_iterator;
    typedef ::xsd::cxx::tree::traits< object_type, char > object_traits;

    const object_sequence&
    object () const;

    object_sequence&
    object ();

    void
    object (const object_sequence& s);

    // name
    //
    typedef ::xml_schema::string name_type;
    typedef ::xsd::cxx::tree::optional< name_type > name_optional;
    typedef ::xsd::cxx::tree::traits< name_type, char > name_traits;

    const name_optional&
    name () const;

    name_optional&
    name ();

    void
    name (const name_type& x);

    void
    name (const name_optional& x);

    void
    name (::std::unique_ptr< name_type > p);

    // Constructors.
    //
    level ();

    level (const ::xercesc::DOMElement& e,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

    level (const level& x,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

    virtual level*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    level&
    operator= (const level& x);

    virtual 
    ~level ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    object_sequence object_;
    name_optional name_;
  };

  class object: public ::xml_schema::type
  {
    public:
    // components
    //
    typedef ::LevelResources::components components_type;
    typedef ::xsd::cxx::tree::traits< components_type, char > components_traits;

    const components_type&
    components () const;

    components_type&
    components ();

    void
    components (const components_type& x);

    void
    components (::std::unique_ptr< components_type > p);

    // name
    //
    typedef ::xml_schema::string name_type;
    typedef ::xsd::cxx::tree::optional< name_type > name_optional;
    typedef ::xsd::cxx::tree::traits< name_type, char > name_traits;

    const name_optional&
    name () const;

    name_optional&
    name ();

    void
    name (const name_type& x);

    void
    name (const name_optional& x);

    void
    name (::std::unique_ptr< name_type > p);

    // Constructors.
    //
    object (const components_type&);

    object (::std::unique_ptr< components_type >);

    object (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    object (const object& x,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    virtual object*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    object&
    operator= (const object& x);

    virtual 
    ~object ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< components_type > components_;
    name_optional name_;
  };

  class components: public ::xml_schema::type
  {
    public:
    // worldPositionComponent
    //
    typedef ::LevelResources::worldPositionComponent worldPositionComponent_type;
    typedef ::xsd::cxx::tree::traits< worldPositionComponent_type, char > worldPositionComponent_traits;

    const worldPositionComponent_type&
    worldPositionComponent () const;

    worldPositionComponent_type&
    worldPositionComponent ();

    void
    worldPositionComponent (const worldPositionComponent_type& x);

    void
    worldPositionComponent (::std::unique_ptr< worldPositionComponent_type > p);

    // physicsComponent
    //
    typedef ::LevelResources::physicsComponent physicsComponent_type;
    typedef ::xsd::cxx::tree::optional< physicsComponent_type > physicsComponent_optional;
    typedef ::xsd::cxx::tree::traits< physicsComponent_type, char > physicsComponent_traits;

    const physicsComponent_optional&
    physicsComponent () const;

    physicsComponent_optional&
    physicsComponent ();

    void
    physicsComponent (const physicsComponent_type& x);

    void
    physicsComponent (const physicsComponent_optional& x);

    void
    physicsComponent (::std::unique_ptr< physicsComponent_type > p);

    // Constructors.
    //
    components (const worldPositionComponent_type&);

    components (::std::unique_ptr< worldPositionComponent_type >);

    components (const ::xercesc::DOMElement& e,
                ::xml_schema::flags f = 0,
                ::xml_schema::container* c = 0);

    components (const components& x,
                ::xml_schema::flags f = 0,
                ::xml_schema::container* c = 0);

    virtual components*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    components&
    operator= (const components& x);

    virtual 
    ~components ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< worldPositionComponent_type > worldPositionComponent_;
    physicsComponent_optional physicsComponent_;
  };

  class worldPositionComponent: public ::xml_schema::type
  {
    public:
    // position
    //
    typedef ::Common::position position_type;
    typedef ::xsd::cxx::tree::traits< position_type, char > position_traits;

    const position_type&
    position () const;

    position_type&
    position ();

    void
    position (const position_type& x);

    void
    position (::std::unique_ptr< position_type > p);

    // Constructors.
    //
    worldPositionComponent (const position_type&);

    worldPositionComponent (::std::unique_ptr< position_type >);

    worldPositionComponent (const ::xercesc::DOMElement& e,
                            ::xml_schema::flags f = 0,
                            ::xml_schema::container* c = 0);

    worldPositionComponent (const worldPositionComponent& x,
                            ::xml_schema::flags f = 0,
                            ::xml_schema::container* c = 0);

    virtual worldPositionComponent*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    worldPositionComponent&
    operator= (const worldPositionComponent& x);

    virtual 
    ~worldPositionComponent ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< position_type > position_;
  };

  class physicsComponent: public ::xml_schema::type
  {
    public:
    // friction
    //
    typedef ::LevelResources::floatCap friction_type;
    typedef ::xsd::cxx::tree::traits< friction_type, char > friction_traits;

    const friction_type&
    friction () const;

    friction_type&
    friction ();

    void
    friction (const friction_type& x);

    void
    friction (::std::unique_ptr< friction_type > p);

    // Constructors.
    //
    physicsComponent (const friction_type&);

    physicsComponent (const ::xercesc::DOMElement& e,
                      ::xml_schema::flags f = 0,
                      ::xml_schema::container* c = 0);

    physicsComponent (const physicsComponent& x,
                      ::xml_schema::flags f = 0,
                      ::xml_schema::container* c = 0);

    virtual physicsComponent*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    physicsComponent&
    operator= (const physicsComponent& x);

    virtual 
    ~physicsComponent ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< friction_type > friction_;
  };
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace LevelResources
{
  // Parse a URI or a local file.
  //

  ::std::unique_ptr< ::LevelResources::level >
  level_ (const ::std::string& uri,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::LevelResources::level >
  level_ (const ::std::string& uri,
          ::xml_schema::error_handler& eh,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::LevelResources::level >
  level_ (const ::std::string& uri,
          ::xercesc::DOMErrorHandler& eh,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  // Parse std::istream.
  //

  ::std::unique_ptr< ::LevelResources::level >
  level_ (::std::istream& is,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::LevelResources::level >
  level_ (::std::istream& is,
          ::xml_schema::error_handler& eh,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::LevelResources::level >
  level_ (::std::istream& is,
          ::xercesc::DOMErrorHandler& eh,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::LevelResources::level >
  level_ (::std::istream& is,
          const ::std::string& id,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::LevelResources::level >
  level_ (::std::istream& is,
          const ::std::string& id,
          ::xml_schema::error_handler& eh,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::LevelResources::level >
  level_ (::std::istream& is,
          const ::std::string& id,
          ::xercesc::DOMErrorHandler& eh,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  // Parse xercesc::InputSource.
  //

  ::std::unique_ptr< ::LevelResources::level >
  level_ (::xercesc::InputSource& is,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::LevelResources::level >
  level_ (::xercesc::InputSource& is,
          ::xml_schema::error_handler& eh,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::LevelResources::level >
  level_ (::xercesc::InputSource& is,
          ::xercesc::DOMErrorHandler& eh,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  // Parse xercesc::DOMDocument.
  //

  ::std::unique_ptr< ::LevelResources::level >
  level_ (const ::xercesc::DOMDocument& d,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::LevelResources::level >
  level_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
          ::xml_schema::flags f = 0,
          const ::xml_schema::properties& p = ::xml_schema::properties ());
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // RESOURCES_XML_SCHEMAS_LEVEL_RESOURCES_HXX
