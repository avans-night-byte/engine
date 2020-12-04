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

#ifndef RESOURCES_XML_SCHEMAS_MENU_HXX
#define RESOURCES_XML_SCHEMAS_MENU_HXX

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
namespace Menu
{
  class menu;
  class buttons;
  class button;
  class resources;
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

namespace Menu
{
  class menu: public ::xml_schema::type
  {
    public:
    // name
    //
    typedef ::xml_schema::string name_type;
    typedef ::xsd::cxx::tree::traits< name_type, char > name_traits;

    const name_type&
    name () const;

    name_type&
    name ();

    void
    name (const name_type& x);

    void
    name (::std::unique_ptr< name_type > p);

    // resources
    //
    typedef ::Common::resources resources_type;
    typedef ::xsd::cxx::tree::traits< resources_type, char > resources_traits;

    const resources_type&
    resources () const;

    resources_type&
    resources ();

    void
    resources (const resources_type& x);

    void
    resources (::std::unique_ptr< resources_type > p);

    // buttons
    //
    typedef ::Menu::buttons buttons_type;
    typedef ::xsd::cxx::tree::traits< buttons_type, char > buttons_traits;

    const buttons_type&
    buttons () const;

    buttons_type&
    buttons ();

    void
    buttons (const buttons_type& x);

    void
    buttons (::std::unique_ptr< buttons_type > p);

    // preloadResources
    //
    typedef ::Common::preloadResources preloadResources_type;
    typedef ::xsd::cxx::tree::traits< preloadResources_type, char > preloadResources_traits;

    const preloadResources_type&
    preloadResources () const;

    preloadResources_type&
    preloadResources ();

    void
    preloadResources (const preloadResources_type& x);

    void
    preloadResources (::std::unique_ptr< preloadResources_type > p);

    // Constructors.
    //
    menu (const name_type&,
          const resources_type&,
          const buttons_type&,
          const preloadResources_type&);

    menu (const name_type&,
          ::std::unique_ptr< resources_type >,
          ::std::unique_ptr< buttons_type >,
          ::std::unique_ptr< preloadResources_type >);

    menu (const ::xercesc::DOMElement& e,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

    menu (const menu& x,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

    virtual menu*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    menu&
    operator= (const menu& x);

    virtual 
    ~menu ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< name_type > name_;
    ::xsd::cxx::tree::one< resources_type > resources_;
    ::xsd::cxx::tree::one< buttons_type > buttons_;
    ::xsd::cxx::tree::one< preloadResources_type > preloadResources_;
  };

  class buttons: public ::xml_schema::type
  {
    public:
    // button
    //
    typedef ::Menu::button button_type;
    typedef ::xsd::cxx::tree::sequence< button_type > button_sequence;
    typedef button_sequence::iterator button_iterator;
    typedef button_sequence::const_iterator button_const_iterator;
    typedef ::xsd::cxx::tree::traits< button_type, char > button_traits;

    const button_sequence&
    button () const;

    button_sequence&
    button ();

    void
    button (const button_sequence& s);

    // Constructors.
    //
    buttons ();

    buttons (const ::xercesc::DOMElement& e,
             ::xml_schema::flags f = 0,
             ::xml_schema::container* c = 0);

    buttons (const buttons& x,
             ::xml_schema::flags f = 0,
             ::xml_schema::container* c = 0);

    virtual buttons*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    buttons&
    operator= (const buttons& x);

    virtual 
    ~buttons ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    button_sequence button_;
  };

  class button: public ::xml_schema::type
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

    // size
    //
    typedef ::Common::size size_type;
    typedef ::xsd::cxx::tree::traits< size_type, char > size_traits;

    const size_type&
    size () const;

    size_type&
    size ();

    void
    size (const size_type& x);

    void
    size (::std::unique_ptr< size_type > p);

    // content
    //
    typedef ::xml_schema::string content_type;
    typedef ::xsd::cxx::tree::traits< content_type, char > content_traits;

    const content_type&
    content () const;

    content_type&
    content ();

    void
    content (const content_type& x);

    void
    content (::std::unique_ptr< content_type > p);

    // color
    //
    typedef ::Common::color color_type;
    typedef ::xsd::cxx::tree::optional< color_type > color_optional;
    typedef ::xsd::cxx::tree::traits< color_type, char > color_traits;

    const color_optional&
    color () const;

    color_optional&
    color ();

    void
    color (const color_type& x);

    void
    color (const color_optional& x);

    void
    color (::std::unique_ptr< color_type > p);

    // resources
    //
    typedef ::Menu::resources resources_type;
    typedef ::xsd::cxx::tree::optional< resources_type > resources_optional;
    typedef ::xsd::cxx::tree::traits< resources_type, char > resources_traits;

    const resources_optional&
    resources () const;

    resources_optional&
    resources ();

    void
    resources (const resources_type& x);

    void
    resources (const resources_optional& x);

    void
    resources (::std::unique_ptr< resources_type > p);

    // events
    //
    typedef ::Common::events events_type;
    typedef ::xsd::cxx::tree::traits< events_type, char > events_traits;

    const events_type&
    events () const;

    events_type&
    events ();

    void
    events (const events_type& x);

    void
    events (::std::unique_ptr< events_type > p);

    // Constructors.
    //
    button (const position_type&,
            const size_type&,
            const content_type&,
            const events_type&);

    button (::std::unique_ptr< position_type >,
            ::std::unique_ptr< size_type >,
            const content_type&,
            ::std::unique_ptr< events_type >);

    button (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    button (const button& x,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    virtual button*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    button&
    operator= (const button& x);

    virtual 
    ~button ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< position_type > position_;
    ::xsd::cxx::tree::one< size_type > size_;
    ::xsd::cxx::tree::one< content_type > content_;
    color_optional color_;
    resources_optional resources_;
    ::xsd::cxx::tree::one< events_type > events_;
  };

  class resources: public ::Common::baseResources
  {
    public:
    // hover
    //
    typedef ::xml_schema::string hover_type;
    typedef ::xsd::cxx::tree::optional< hover_type > hover_optional;
    typedef ::xsd::cxx::tree::traits< hover_type, char > hover_traits;

    const hover_optional&
    hover () const;

    hover_optional&
    hover ();

    void
    hover (const hover_type& x);

    void
    hover (const hover_optional& x);

    void
    hover (::std::unique_ptr< hover_type > p);

    // click
    //
    typedef ::xml_schema::string click_type;
    typedef ::xsd::cxx::tree::optional< click_type > click_optional;
    typedef ::xsd::cxx::tree::traits< click_type, char > click_traits;

    const click_optional&
    click () const;

    click_optional&
    click ();

    void
    click (const click_type& x);

    void
    click (const click_optional& x);

    void
    click (::std::unique_ptr< click_type > p);

    // Constructors.
    //
    resources (const default_type&);

    resources (const ::xercesc::DOMElement& e,
               ::xml_schema::flags f = 0,
               ::xml_schema::container* c = 0);

    resources (const resources& x,
               ::xml_schema::flags f = 0,
               ::xml_schema::container* c = 0);

    virtual resources*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    resources&
    operator= (const resources& x);

    virtual 
    ~resources ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    hover_optional hover_;
    click_optional click_;
  };
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace Menu
{
  // Parse a URI or a local file.
  //

  ::std::unique_ptr< ::Menu::menu >
  menu_ (const ::std::string& uri,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::Menu::menu >
  menu_ (const ::std::string& uri,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::Menu::menu >
  menu_ (const ::std::string& uri,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  // Parse std::istream.
  //

  ::std::unique_ptr< ::Menu::menu >
  menu_ (::std::istream& is,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::Menu::menu >
  menu_ (::std::istream& is,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::Menu::menu >
  menu_ (::std::istream& is,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::Menu::menu >
  menu_ (::std::istream& is,
         const ::std::string& id,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::Menu::menu >
  menu_ (::std::istream& is,
         const ::std::string& id,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::Menu::menu >
  menu_ (::std::istream& is,
         const ::std::string& id,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  // Parse xercesc::InputSource.
  //

  ::std::unique_ptr< ::Menu::menu >
  menu_ (::xercesc::InputSource& is,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::Menu::menu >
  menu_ (::xercesc::InputSource& is,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::Menu::menu >
  menu_ (::xercesc::InputSource& is,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  // Parse xercesc::DOMDocument.
  //

  ::std::unique_ptr< ::Menu::menu >
  menu_ (const ::xercesc::DOMDocument& d,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::Menu::menu >
  menu_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // RESOURCES_XML_SCHEMAS_MENU_HXX
