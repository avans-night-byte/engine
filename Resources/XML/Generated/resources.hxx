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

#ifndef RESOURCES_XML_SCHEMAS_RESOURCES_HXX
#define RESOURCES_XML_SCHEMAS_RESOURCES_HXX

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
namespace GameResources
{
  class baseGameResource;
  class gameResources;
  class textures;
  class sprites;
  class sounds;
  class music;
  class scenes;
  class levels;
  class texture;
  class sprite;
  class sound;
  class music1;
  class scene;
  class level;
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

namespace GameResources
{
  class baseGameResource: public ::xml_schema::type
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

    // path
    //
    typedef ::xml_schema::string path_type;
    typedef ::xsd::cxx::tree::traits< path_type, char > path_traits;

    const path_type&
    path () const;

    path_type&
    path ();

    void
    path (const path_type& x);

    void
    path (::std::unique_ptr< path_type > p);

    // Constructors.
    //
    baseGameResource (const name_type&,
                      const path_type&);

    baseGameResource (const ::xercesc::DOMElement& e,
                      ::xml_schema::flags f = 0,
                      ::xml_schema::container* c = 0);

    baseGameResource (const baseGameResource& x,
                      ::xml_schema::flags f = 0,
                      ::xml_schema::container* c = 0);

    virtual baseGameResource*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    baseGameResource&
    operator= (const baseGameResource& x);

    virtual 
    ~baseGameResource ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< name_type > name_;
    ::xsd::cxx::tree::one< path_type > path_;
  };

  class gameResources: public ::xml_schema::type
  {
    public:
    // textures
    //
    typedef ::GameResources::textures textures_type;
    typedef ::xsd::cxx::tree::traits< textures_type, char > textures_traits;

    const textures_type&
    textures () const;

    textures_type&
    textures ();

    void
    textures (const textures_type& x);

    void
    textures (::std::unique_ptr< textures_type > p);

    // sprites
    //
    typedef ::GameResources::sprites sprites_type;
    typedef ::xsd::cxx::tree::traits< sprites_type, char > sprites_traits;

    const sprites_type&
    sprites () const;

    sprites_type&
    sprites ();

    void
    sprites (const sprites_type& x);

    void
    sprites (::std::unique_ptr< sprites_type > p);

    // sounds
    //
    typedef ::GameResources::sounds sounds_type;
    typedef ::xsd::cxx::tree::traits< sounds_type, char > sounds_traits;

    const sounds_type&
    sounds () const;

    sounds_type&
    sounds ();

    void
    sounds (const sounds_type& x);

    void
    sounds (::std::unique_ptr< sounds_type > p);

    // music
    //
    typedef ::GameResources::music music_type;
    typedef ::xsd::cxx::tree::traits< music_type, char > music_traits;

    const music_type&
    music () const;

    music_type&
    music ();

    void
    music (const music_type& x);

    void
    music (::std::unique_ptr< music_type > p);

    // scenes
    //
    typedef ::GameResources::scenes scenes_type;
    typedef ::xsd::cxx::tree::traits< scenes_type, char > scenes_traits;

    const scenes_type&
    scenes () const;

    scenes_type&
    scenes ();

    void
    scenes (const scenes_type& x);

    void
    scenes (::std::unique_ptr< scenes_type > p);

    // levels
    //
    typedef ::GameResources::levels levels_type;
    typedef ::xsd::cxx::tree::traits< levels_type, char > levels_traits;

    const levels_type&
    levels () const;

    levels_type&
    levels ();

    void
    levels (const levels_type& x);

    void
    levels (::std::unique_ptr< levels_type > p);

    // Constructors.
    //
    gameResources (const textures_type&,
                   const sprites_type&,
                   const sounds_type&,
                   const music_type&,
                   const scenes_type&,
                   const levels_type&);

    gameResources (::std::unique_ptr< textures_type >,
                   ::std::unique_ptr< sprites_type >,
                   ::std::unique_ptr< sounds_type >,
                   ::std::unique_ptr< music_type >,
                   ::std::unique_ptr< scenes_type >,
                   ::std::unique_ptr< levels_type >);

    gameResources (const ::xercesc::DOMElement& e,
                   ::xml_schema::flags f = 0,
                   ::xml_schema::container* c = 0);

    gameResources (const gameResources& x,
                   ::xml_schema::flags f = 0,
                   ::xml_schema::container* c = 0);

    virtual gameResources*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    gameResources&
    operator= (const gameResources& x);

    virtual 
    ~gameResources ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< textures_type > textures_;
    ::xsd::cxx::tree::one< sprites_type > sprites_;
    ::xsd::cxx::tree::one< sounds_type > sounds_;
    ::xsd::cxx::tree::one< music_type > music_;
    ::xsd::cxx::tree::one< scenes_type > scenes_;
    ::xsd::cxx::tree::one< levels_type > levels_;
  };

  class textures: public ::xml_schema::type
  {
    public:
    // texture
    //
    typedef ::GameResources::texture texture_type;
    typedef ::xsd::cxx::tree::sequence< texture_type > texture_sequence;
    typedef texture_sequence::iterator texture_iterator;
    typedef texture_sequence::const_iterator texture_const_iterator;
    typedef ::xsd::cxx::tree::traits< texture_type, char > texture_traits;

    const texture_sequence&
    texture () const;

    texture_sequence&
    texture ();

    void
    texture (const texture_sequence& s);

    // Constructors.
    //
    textures ();

    textures (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    textures (const textures& x,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    virtual textures*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    textures&
    operator= (const textures& x);

    virtual 
    ~textures ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    texture_sequence texture_;
  };

  class sprites: public ::xml_schema::type
  {
    public:
    // sprite
    //
    typedef ::GameResources::sprite sprite_type;
    typedef ::xsd::cxx::tree::sequence< sprite_type > sprite_sequence;
    typedef sprite_sequence::iterator sprite_iterator;
    typedef sprite_sequence::const_iterator sprite_const_iterator;
    typedef ::xsd::cxx::tree::traits< sprite_type, char > sprite_traits;

    const sprite_sequence&
    sprite () const;

    sprite_sequence&
    sprite ();

    void
    sprite (const sprite_sequence& s);

    // Constructors.
    //
    sprites ();

    sprites (const ::xercesc::DOMElement& e,
             ::xml_schema::flags f = 0,
             ::xml_schema::container* c = 0);

    sprites (const sprites& x,
             ::xml_schema::flags f = 0,
             ::xml_schema::container* c = 0);

    virtual sprites*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    sprites&
    operator= (const sprites& x);

    virtual 
    ~sprites ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    sprite_sequence sprite_;
  };

  class sounds: public ::xml_schema::type
  {
    public:
    // sound
    //
    typedef ::GameResources::sound sound_type;
    typedef ::xsd::cxx::tree::sequence< sound_type > sound_sequence;
    typedef sound_sequence::iterator sound_iterator;
    typedef sound_sequence::const_iterator sound_const_iterator;
    typedef ::xsd::cxx::tree::traits< sound_type, char > sound_traits;

    const sound_sequence&
    sound () const;

    sound_sequence&
    sound ();

    void
    sound (const sound_sequence& s);

    // Constructors.
    //
    sounds ();

    sounds (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    sounds (const sounds& x,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    virtual sounds*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    sounds&
    operator= (const sounds& x);

    virtual 
    ~sounds ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    sound_sequence sound_;
  };

  class music: public ::xml_schema::type
  {
    public:
    // music
    //
    typedef ::GameResources::music1 music1_type;
    typedef ::xsd::cxx::tree::sequence< music1_type > music1_sequence;
    typedef music1_sequence::iterator music1_iterator;
    typedef music1_sequence::const_iterator music1_const_iterator;
    typedef ::xsd::cxx::tree::traits< music1_type, char > music1_traits;

    const music1_sequence&
    music1 () const;

    music1_sequence&
    music1 ();

    void
    music1 (const music1_sequence& s);

    // Constructors.
    //
    music ();

    music (const ::xercesc::DOMElement& e,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

    music (const music& x,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

    virtual music*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    music&
    operator= (const music& x);

    virtual 
    ~music ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    music1_sequence music1_;
  };

  class scenes: public ::xml_schema::type
  {
    public:
    // scene
    //
    typedef ::GameResources::scene scene_type;
    typedef ::xsd::cxx::tree::sequence< scene_type > scene_sequence;
    typedef scene_sequence::iterator scene_iterator;
    typedef scene_sequence::const_iterator scene_const_iterator;
    typedef ::xsd::cxx::tree::traits< scene_type, char > scene_traits;

    const scene_sequence&
    scene () const;

    scene_sequence&
    scene ();

    void
    scene (const scene_sequence& s);

    // Constructors.
    //
    scenes ();

    scenes (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    scenes (const scenes& x,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    virtual scenes*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    scenes&
    operator= (const scenes& x);

    virtual 
    ~scenes ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    scene_sequence scene_;
  };

  class levels: public ::xml_schema::type
  {
    public:
    // level
    //
    typedef ::GameResources::level level_type;
    typedef ::xsd::cxx::tree::sequence< level_type > level_sequence;
    typedef level_sequence::iterator level_iterator;
    typedef level_sequence::const_iterator level_const_iterator;
    typedef ::xsd::cxx::tree::traits< level_type, char > level_traits;

    const level_sequence&
    level () const;

    level_sequence&
    level ();

    void
    level (const level_sequence& s);

    // Constructors.
    //
    levels ();

    levels (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    levels (const levels& x,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    virtual levels*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    levels&
    operator= (const levels& x);

    virtual 
    ~levels ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    level_sequence level_;
  };

  class texture: public ::GameResources::baseGameResource
  {
    public:
    // Constructors.
    //
    texture (const name_type&,
             const path_type&);

    texture (const ::xercesc::DOMElement& e,
             ::xml_schema::flags f = 0,
             ::xml_schema::container* c = 0);

    texture (const texture& x,
             ::xml_schema::flags f = 0,
             ::xml_schema::container* c = 0);

    virtual texture*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~texture ();
  };

  class sprite: public ::GameResources::baseGameResource
  {
    public:
    // definition
    //
    typedef ::xml_schema::string definition_type;
    typedef ::xsd::cxx::tree::optional< definition_type > definition_optional;
    typedef ::xsd::cxx::tree::traits< definition_type, char > definition_traits;

    const definition_optional&
    definition () const;

    definition_optional&
    definition ();

    void
    definition (const definition_type& x);

    void
    definition (const definition_optional& x);

    void
    definition (::std::unique_ptr< definition_type > p);

    // size
    //
    typedef ::Common::size size_type;
    typedef ::xsd::cxx::tree::optional< size_type > size_optional;
    typedef ::xsd::cxx::tree::traits< size_type, char > size_traits;

    const size_optional&
    size () const;

    size_optional&
    size ();

    void
    size (const size_type& x);

    void
    size (const size_optional& x);

    void
    size (::std::unique_ptr< size_type > p);

    // Constructors.
    //
    sprite (const name_type&,
            const path_type&);

    sprite (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    sprite (const sprite& x,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    virtual sprite*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    sprite&
    operator= (const sprite& x);

    virtual 
    ~sprite ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    definition_optional definition_;
    size_optional size_;
  };

  class sound: public ::GameResources::baseGameResource
  {
    public:
    // Constructors.
    //
    sound (const name_type&,
           const path_type&);

    sound (const ::xercesc::DOMElement& e,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

    sound (const sound& x,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

    virtual sound*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~sound ();
  };

  class music1: public ::GameResources::baseGameResource
  {
    public:
    // Constructors.
    //
    music1 (const name_type&,
            const path_type&);

    music1 (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    music1 (const music1& x,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

    virtual music1*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~music1 ();
  };

  class scene: public ::GameResources::baseGameResource
  {
    public:
    // Constructors.
    //
    scene (const name_type&,
           const path_type&);

    scene (const ::xercesc::DOMElement& e,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

    scene (const scene& x,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

    virtual scene*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~scene ();
  };

  class level: public ::GameResources::baseGameResource
  {
    public:
    // Constructors.
    //
    level (const name_type&,
           const path_type&);

    level (const ::xercesc::DOMElement& e,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

    level (const level& x,
           ::xml_schema::flags f = 0,
           ::xml_schema::container* c = 0);

    virtual level*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~level ();
  };
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace GameResources
{
  // Parse a URI or a local file.
  //

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (const ::std::string& uri,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (const ::std::string& uri,
                  ::xml_schema::error_handler& eh,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (const ::std::string& uri,
                  ::xercesc::DOMErrorHandler& eh,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  // Parse std::istream.
  //

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (::std::istream& is,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (::std::istream& is,
                  ::xml_schema::error_handler& eh,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (::std::istream& is,
                  ::xercesc::DOMErrorHandler& eh,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (::std::istream& is,
                  const ::std::string& id,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (::std::istream& is,
                  const ::std::string& id,
                  ::xml_schema::error_handler& eh,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (::std::istream& is,
                  const ::std::string& id,
                  ::xercesc::DOMErrorHandler& eh,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  // Parse xercesc::InputSource.
  //

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (::xercesc::InputSource& is,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (::xercesc::InputSource& is,
                  ::xml_schema::error_handler& eh,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (::xercesc::InputSource& is,
                  ::xercesc::DOMErrorHandler& eh,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  // Parse xercesc::DOMDocument.
  //

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (const ::xercesc::DOMDocument& d,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::unique_ptr< ::GameResources::gameResources >
  gameResources_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
                  ::xml_schema::flags f = 0,
                  const ::xml_schema::properties& p = ::xml_schema::properties ());
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // RESOURCES_XML_SCHEMAS_RESOURCES_HXX