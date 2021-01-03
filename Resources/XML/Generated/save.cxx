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

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "save.hxx"

namespace Save
{
  // save
  // 

  const save::playerData_type& save::
  playerData () const
  {
    return this->playerData_.get ();
  }

  save::playerData_type& save::
  playerData ()
  {
    return this->playerData_.get ();
  }

  void save::
  playerData (const playerData_type& x)
  {
    this->playerData_.set (x);
  }

  void save::
  playerData (::std::unique_ptr< playerData_type > x)
  {
    this->playerData_.set (std::move (x));
  }

  const save::inventoryData_type& save::
  inventoryData () const
  {
    return this->inventoryData_.get ();
  }

  save::inventoryData_type& save::
  inventoryData ()
  {
    return this->inventoryData_.get ();
  }

  void save::
  inventoryData (const inventoryData_type& x)
  {
    this->inventoryData_.set (x);
  }

  void save::
  inventoryData (::std::unique_ptr< inventoryData_type > x)
  {
    this->inventoryData_.set (std::move (x));
  }

  const save::objectData_type& save::
  objectData () const
  {
    return this->objectData_.get ();
  }

  save::objectData_type& save::
  objectData ()
  {
    return this->objectData_.get ();
  }

  void save::
  objectData (const objectData_type& x)
  {
    this->objectData_.set (x);
  }

  void save::
  objectData (::std::unique_ptr< objectData_type > x)
  {
    this->objectData_.set (std::move (x));
  }


  // playerData
  // 

  const playerData::position_type& playerData::
  position () const
  {
    return this->position_.get ();
  }

  playerData::position_type& playerData::
  position ()
  {
    return this->position_.get ();
  }

  void playerData::
  position (const position_type& x)
  {
    this->position_.set (x);
  }

  void playerData::
  position (::std::unique_ptr< position_type > x)
  {
    this->position_.set (std::move (x));
  }

  const playerData::health_type& playerData::
  health () const
  {
    return this->health_.get ();
  }

  playerData::health_type& playerData::
  health ()
  {
    return this->health_.get ();
  }

  void playerData::
  health (const health_type& x)
  {
    this->health_.set (x);
  }

  const playerData::money_type& playerData::
  money () const
  {
    return this->money_.get ();
  }

  playerData::money_type& playerData::
  money ()
  {
    return this->money_.get ();
  }

  void playerData::
  money (const money_type& x)
  {
    this->money_.set (x);
  }

  const playerData::level_type& playerData::
  level () const
  {
    return this->level_.get ();
  }

  playerData::level_type& playerData::
  level ()
  {
    return this->level_.get ();
  }

  void playerData::
  level (const level_type& x)
  {
    this->level_.set (x);
  }

  void playerData::
  level (::std::unique_ptr< level_type > x)
  {
    this->level_.set (std::move (x));
  }


  // inventoryData
  // 

  const inventoryData::item_sequence& inventoryData::
  item () const
  {
    return this->item_;
  }

  inventoryData::item_sequence& inventoryData::
  item ()
  {
    return this->item_;
  }

  void inventoryData::
  item (const item_sequence& s)
  {
    this->item_ = s;
  }


  // objectData
  // 


  // item
  // 

  const item::name_type& item::
  name () const
  {
    return this->name_.get ();
  }

  item::name_type& item::
  name ()
  {
    return this->name_.get ();
  }

  void item::
  name (const name_type& x)
  {
    this->name_.set (x);
  }

  void item::
  name (::std::unique_ptr< name_type > x)
  {
    this->name_.set (std::move (x));
  }

  const item::quantity_type& item::
  quantity () const
  {
    return this->quantity_.get ();
  }

  item::quantity_type& item::
  quantity ()
  {
    return this->quantity_.get ();
  }

  void item::
  quantity (const quantity_type& x)
  {
    this->quantity_.set (x);
  }

  const item::type_type& item::
  type () const
  {
    return this->type_.get ();
  }

  item::type_type& item::
  type ()
  {
    return this->type_.get ();
  }

  void item::
  type (const type_type& x)
  {
    this->type_.set (x);
  }

  void item::
  type (::std::unique_ptr< type_type > x)
  {
    this->type_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace Save
{
  // save
  //

  save::
  save (const playerData_type& playerData,
        const inventoryData_type& inventoryData,
        const objectData_type& objectData)
  : ::xml_schema::type (),
    playerData_ (playerData, this),
    inventoryData_ (inventoryData, this),
    objectData_ (objectData, this)
  {
  }

  save::
  save (::std::unique_ptr< playerData_type > playerData,
        ::std::unique_ptr< inventoryData_type > inventoryData,
        const objectData_type& objectData)
  : ::xml_schema::type (),
    playerData_ (std::move (playerData), this),
    inventoryData_ (std::move (inventoryData), this),
    objectData_ (objectData, this)
  {
  }

  save::
  save (const save& x,
        ::xml_schema::flags f,
        ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    playerData_ (x.playerData_, f, this),
    inventoryData_ (x.inventoryData_, f, this),
    objectData_ (x.objectData_, f, this)
  {
  }

  save::
  save (const ::xercesc::DOMElement& e,
        ::xml_schema::flags f,
        ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    playerData_ (this),
    inventoryData_ (this),
    objectData_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void save::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // playerData
      //
      if (n.name () == "playerData" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< playerData_type > r (
          playerData_traits::create (i, f, this));

        if (!playerData_.present ())
        {
          this->playerData_.set (::std::move (r));
          continue;
        }
      }

      // inventoryData
      //
      if (n.name () == "inventoryData" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< inventoryData_type > r (
          inventoryData_traits::create (i, f, this));

        if (!inventoryData_.present ())
        {
          this->inventoryData_.set (::std::move (r));
          continue;
        }
      }

      // objectData
      //
      if (n.name () == "objectData" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< objectData_type > r (
          objectData_traits::create (i, f, this));

        if (!objectData_.present ())
        {
          this->objectData_.set (::std::move (r));
          continue;
        }
      }

      break;
    }

    if (!playerData_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "playerData",
        "");
    }

    if (!inventoryData_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "inventoryData",
        "");
    }

    if (!objectData_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "objectData",
        "");
    }
  }

  save* save::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class save (*this, f, c);
  }

  save& save::
  operator= (const save& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->playerData_ = x.playerData_;
      this->inventoryData_ = x.inventoryData_;
      this->objectData_ = x.objectData_;
    }

    return *this;
  }

  save::
  ~save ()
  {
  }

  // playerData
  //

  playerData::
  playerData (const position_type& position,
              const health_type& health,
              const money_type& money,
              const level_type& level)
  : ::xml_schema::type (),
    position_ (position, this),
    health_ (health, this),
    money_ (money, this),
    level_ (level, this)
  {
  }

  playerData::
  playerData (::std::unique_ptr< position_type > position,
              const health_type& health,
              const money_type& money,
              const level_type& level)
  : ::xml_schema::type (),
    position_ (std::move (position), this),
    health_ (health, this),
    money_ (money, this),
    level_ (level, this)
  {
  }

  playerData::
  playerData (const playerData& x,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    position_ (x.position_, f, this),
    health_ (x.health_, f, this),
    money_ (x.money_, f, this),
    level_ (x.level_, f, this)
  {
  }

  playerData::
  playerData (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    position_ (this),
    health_ (this),
    money_ (this),
    level_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void playerData::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // position
      //
      if (n.name () == "position" && n.namespace_ () == "Common")
      {
        ::std::unique_ptr< position_type > r (
          position_traits::create (i, f, this));

        if (!position_.present ())
        {
          this->position_.set (::std::move (r));
          continue;
        }
      }

      // health
      //
      if (n.name () == "health" && n.namespace_ ().empty ())
      {
        if (!health_.present ())
        {
          this->health_.set (health_traits::create (i, f, this));
          continue;
        }
      }

      // money
      //
      if (n.name () == "money" && n.namespace_ ().empty ())
      {
        if (!money_.present ())
        {
          this->money_.set (money_traits::create (i, f, this));
          continue;
        }
      }

      // level
      //
      if (n.name () == "level" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< level_type > r (
          level_traits::create (i, f, this));

        if (!level_.present ())
        {
          this->level_.set (::std::move (r));
          continue;
        }
      }

      break;
    }

    if (!position_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "position",
        "Common");
    }

    if (!health_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "health",
        "");
    }

    if (!money_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "money",
        "");
    }

    if (!level_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "level",
        "");
    }
  }

  playerData* playerData::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class playerData (*this, f, c);
  }

  playerData& playerData::
  operator= (const playerData& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->position_ = x.position_;
      this->health_ = x.health_;
      this->money_ = x.money_;
      this->level_ = x.level_;
    }

    return *this;
  }

  playerData::
  ~playerData ()
  {
  }

  // inventoryData
  //

  inventoryData::
  inventoryData ()
  : ::xml_schema::type (),
    item_ (this)
  {
  }

  inventoryData::
  inventoryData (const inventoryData& x,
                 ::xml_schema::flags f,
                 ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    item_ (x.item_, f, this)
  {
  }

  inventoryData::
  inventoryData (const ::xercesc::DOMElement& e,
                 ::xml_schema::flags f,
                 ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    item_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void inventoryData::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // item
      //
      if (n.name () == "item" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< item_type > r (
          item_traits::create (i, f, this));

        this->item_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  inventoryData* inventoryData::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class inventoryData (*this, f, c);
  }

  inventoryData& inventoryData::
  operator= (const inventoryData& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->item_ = x.item_;
    }

    return *this;
  }

  inventoryData::
  ~inventoryData ()
  {
  }

  // objectData
  //

  objectData::
  objectData ()
  : ::xml_schema::type ()
  {
  }

  objectData::
  objectData (const objectData& x,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c)
  {
  }

  objectData::
  objectData (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::xml_schema::type (e, f, c)
  {
  }

  objectData::
  objectData (const ::xercesc::DOMAttr& a,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::xml_schema::type (a, f, c)
  {
  }

  objectData::
  objectData (const ::std::string& s,
              const ::xercesc::DOMElement* e,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::xml_schema::type (s, e, f, c)
  {
  }

  objectData* objectData::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class objectData (*this, f, c);
  }

  objectData::
  ~objectData ()
  {
  }

  // item
  //

  item::
  item (const name_type& name,
        const quantity_type& quantity,
        const type_type& type)
  : ::xml_schema::type (),
    name_ (name, this),
    quantity_ (quantity, this),
    type_ (type, this)
  {
  }

  item::
  item (const item& x,
        ::xml_schema::flags f,
        ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    name_ (x.name_, f, this),
    quantity_ (x.quantity_, f, this),
    type_ (x.type_, f, this)
  {
  }

  item::
  item (const ::xercesc::DOMElement& e,
        ::xml_schema::flags f,
        ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    name_ (this),
    quantity_ (this),
    type_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void item::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // name
      //
      if (n.name () == "name" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< name_type > r (
          name_traits::create (i, f, this));

        if (!name_.present ())
        {
          this->name_.set (::std::move (r));
          continue;
        }
      }

      // quantity
      //
      if (n.name () == "quantity" && n.namespace_ ().empty ())
      {
        if (!quantity_.present ())
        {
          this->quantity_.set (quantity_traits::create (i, f, this));
          continue;
        }
      }

      // type
      //
      if (n.name () == "type" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< type_type > r (
          type_traits::create (i, f, this));

        if (!type_.present ())
        {
          this->type_.set (::std::move (r));
          continue;
        }
      }

      break;
    }

    if (!name_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "name",
        "");
    }

    if (!quantity_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "quantity",
        "");
    }

    if (!type_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "type",
        "");
    }
  }

  item* item::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class item (*this, f, c);
  }

  item& item::
  operator= (const item& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->name_ = x.name_;
      this->quantity_ = x.quantity_;
      this->type_ = x.type_;
    }

    return *this;
  }

  item::
  ~item ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace Save
{
  ::std::unique_ptr< ::Save::save >
  save_ (const ::std::string& u,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::tree::error_handler< char > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (
        u, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

    return ::std::unique_ptr< ::Save::save > (
      ::Save::save_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::Save::save >
  save_ (const ::std::string& u,
         ::xml_schema::error_handler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< char > ();

    return ::std::unique_ptr< ::Save::save > (
      ::Save::save_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::Save::save >
  save_ (const ::std::string& u,
         ::xercesc::DOMErrorHandler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< char > ();

    return ::std::unique_ptr< ::Save::save > (
      ::Save::save_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::Save::save >
  save_ (::std::istream& is,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::Save::save_ (isrc, f, p);
  }

  ::std::unique_ptr< ::Save::save >
  save_ (::std::istream& is,
         ::xml_schema::error_handler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::Save::save_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::Save::save >
  save_ (::std::istream& is,
         ::xercesc::DOMErrorHandler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::Save::save_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::Save::save >
  save_ (::std::istream& is,
         const ::std::string& sid,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::Save::save_ (isrc, f, p);
  }

  ::std::unique_ptr< ::Save::save >
  save_ (::std::istream& is,
         const ::std::string& sid,
         ::xml_schema::error_handler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::Save::save_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::Save::save >
  save_ (::std::istream& is,
         const ::std::string& sid,
         ::xercesc::DOMErrorHandler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::Save::save_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::Save::save >
  save_ (::xercesc::InputSource& i,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::tree::error_handler< char > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (
        i, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

    return ::std::unique_ptr< ::Save::save > (
      ::Save::save_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::Save::save >
  save_ (::xercesc::InputSource& i,
         ::xml_schema::error_handler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< char > ();

    return ::std::unique_ptr< ::Save::save > (
      ::Save::save_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::Save::save >
  save_ (::xercesc::InputSource& i,
         ::xercesc::DOMErrorHandler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< char > ();

    return ::std::unique_ptr< ::Save::save > (
      ::Save::save_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::Save::save >
  save_ (const ::xercesc::DOMDocument& doc,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

      return ::std::unique_ptr< ::Save::save > (
        ::Save::save_ (
          std::move (d), f | ::xml_schema::flags::own_dom, p));
    }

    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (e));

    if (n.name () == "save" &&
        n.namespace_ () == "Save")
    {
      ::std::unique_ptr< ::Save::save > r (
        ::xsd::cxx::tree::traits< ::Save::save, char >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < char > (
      n.name (),
      n.namespace_ (),
      "save",
      "Save");
  }

  ::std::unique_ptr< ::Save::save >
  save_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
         ::xml_schema::flags f,
         const ::xml_schema::properties&)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > c (
      ((f & ::xml_schema::flags::keep_dom) &&
       !(f & ::xml_schema::flags::own_dom))
      ? static_cast< ::xercesc::DOMDocument* > (d->cloneNode (true))
      : 0);

    ::xercesc::DOMDocument& doc (c.get () ? *c : *d);
    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());

    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (e));

    if (f & ::xml_schema::flags::keep_dom)
      doc.setUserData (::xml_schema::dom::tree_node_key,
                       (c.get () ? &c : &d),
                       0);

    if (n.name () == "save" &&
        n.namespace_ () == "Save")
    {
      ::std::unique_ptr< ::Save::save > r (
        ::xsd::cxx::tree::traits< ::Save::save, char >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < char > (
      n.name (),
      n.namespace_ (),
      "save",
      "Save");
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

