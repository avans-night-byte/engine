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

#include "objects.hxx"

namespace Objects
{
  // object
  // 

  const object::name_type& object::
  name () const
  {
    return this->name_.get ();
  }

  object::name_type& object::
  name ()
  {
    return this->name_.get ();
  }

  void object::
  name (const name_type& x)
  {
    this->name_.set (x);
  }

  void object::
  name (::std::unique_ptr< name_type > x)
  {
    this->name_.set (std::move (x));
  }

  const object::objectType_type& object::
  objectType () const
  {
    return this->objectType_.get ();
  }

  object::objectType_type& object::
  objectType ()
  {
    return this->objectType_.get ();
  }

  void object::
  objectType (const objectType_type& x)
  {
    this->objectType_.set (x);
  }

  void object::
  objectType (::std::unique_ptr< objectType_type > x)
  {
    this->objectType_.set (std::move (x));
  }

  const object::components_type& object::
  components () const
  {
    return this->components_.get ();
  }

  object::components_type& object::
  components ()
  {
    return this->components_.get ();
  }

  void object::
  components (const components_type& x)
  {
    this->components_.set (x);
  }

  void object::
  components (::std::unique_ptr< components_type > x)
  {
    this->components_.set (std::move (x));
  }


  // objectList
  // 

  const objectList::object_sequence& objectList::
  object () const
  {
    return this->object_;
  }

  objectList::object_sequence& objectList::
  object ()
  {
    return this->object_;
  }

  void objectList::
  object (const object_sequence& s)
  {
    this->object_ = s;
  }

  const objectList::preloadResources_type& objectList::
  preloadResources () const
  {
    return this->preloadResources_.get ();
  }

  objectList::preloadResources_type& objectList::
  preloadResources ()
  {
    return this->preloadResources_.get ();
  }

  void objectList::
  preloadResources (const preloadResources_type& x)
  {
    this->preloadResources_.set (x);
  }

  void objectList::
  preloadResources (::std::unique_ptr< preloadResources_type > x)
  {
    this->preloadResources_.set (std::move (x));
  }


  // components
  // 

  const components::component_sequence& components::
  component () const
  {
    return this->component_;
  }

  components::component_sequence& components::
  component ()
  {
    return this->component_;
  }

  void components::
  component (const component_sequence& s)
  {
    this->component_ = s;
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace Objects
{
  // object
  //

  object::
  object (const name_type& name,
          const objectType_type& objectType,
          const components_type& components)
  : ::xml_schema::type (),
    name_ (name, this),
    objectType_ (objectType, this),
    components_ (components, this)
  {
  }

  object::
  object (const name_type& name,
          const objectType_type& objectType,
          ::std::unique_ptr< components_type > components)
  : ::xml_schema::type (),
    name_ (name, this),
    objectType_ (objectType, this),
    components_ (std::move (components), this)
  {
  }

  object::
  object (const object& x,
          ::xml_schema::flags f,
          ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    name_ (x.name_, f, this),
    objectType_ (x.objectType_, f, this),
    components_ (x.components_, f, this)
  {
  }

  object::
  object (const ::xercesc::DOMElement& e,
          ::xml_schema::flags f,
          ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    name_ (this),
    objectType_ (this),
    components_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void object::
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

      // objectType
      //
      if (n.name () == "objectType" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< objectType_type > r (
          objectType_traits::create (i, f, this));

        if (!objectType_.present ())
        {
          this->objectType_.set (::std::move (r));
          continue;
        }
      }

      // components
      //
      if (n.name () == "components" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< components_type > r (
          components_traits::create (i, f, this));

        if (!components_.present ())
        {
          this->components_.set (::std::move (r));
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

    if (!objectType_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "objectType",
        "");
    }

    if (!components_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "components",
        "");
    }
  }

  object* object::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class object (*this, f, c);
  }

  object& object::
  operator= (const object& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->name_ = x.name_;
      this->objectType_ = x.objectType_;
      this->components_ = x.components_;
    }

    return *this;
  }

  object::
  ~object ()
  {
  }

  // objectList
  //

  objectList::
  objectList (const preloadResources_type& preloadResources)
  : ::xml_schema::type (),
    object_ (this),
    preloadResources_ (preloadResources, this)
  {
  }

  objectList::
  objectList (::std::unique_ptr< preloadResources_type > preloadResources)
  : ::xml_schema::type (),
    object_ (this),
    preloadResources_ (std::move (preloadResources), this)
  {
  }

  objectList::
  objectList (const objectList& x,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    object_ (x.object_, f, this),
    preloadResources_ (x.preloadResources_, f, this)
  {
  }

  objectList::
  objectList (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    object_ (this),
    preloadResources_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void objectList::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // object
      //
      if (n.name () == "object" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< object_type > r (
          object_traits::create (i, f, this));

        this->object_.push_back (::std::move (r));
        continue;
      }

      // preloadResources
      //
      if (n.name () == "preloadResources" && n.namespace_ () == "Common")
      {
        ::std::unique_ptr< preloadResources_type > r (
          preloadResources_traits::create (i, f, this));

        if (!preloadResources_.present ())
        {
          this->preloadResources_.set (::std::move (r));
          continue;
        }
      }

      break;
    }

    if (!preloadResources_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "preloadResources",
        "Common");
    }
  }

  objectList* objectList::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class objectList (*this, f, c);
  }

  objectList& objectList::
  operator= (const objectList& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->object_ = x.object_;
      this->preloadResources_ = x.preloadResources_;
    }

    return *this;
  }

  objectList::
  ~objectList ()
  {
  }

  // components
  //

  components::
  components ()
  : ::xml_schema::type (),
    component_ (this)
  {
  }

  components::
  components (const components& x,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    component_ (x.component_, f, this)
  {
  }

  components::
  components (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    component_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void components::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // component
      //
      if (n.name () == "component" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< component_type > r (
          component_traits::create (i, f, this));

        this->component_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  components* components::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class components (*this, f, c);
  }

  components& components::
  operator= (const components& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->component_ = x.component_;
    }

    return *this;
  }

  components::
  ~components ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace Objects
{
  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (const ::std::string& u,
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

    return ::std::unique_ptr< ::Objects::objectList > (
      ::Objects::objectList_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (const ::std::string& u,
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

    return ::std::unique_ptr< ::Objects::objectList > (
      ::Objects::objectList_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (const ::std::string& u,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< char > ();

    return ::std::unique_ptr< ::Objects::objectList > (
      ::Objects::objectList_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (::std::istream& is,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::Objects::objectList_ (isrc, f, p);
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (::std::istream& is,
               ::xml_schema::error_handler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::Objects::objectList_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (::std::istream& is,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::Objects::objectList_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (::std::istream& is,
               const ::std::string& sid,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::Objects::objectList_ (isrc, f, p);
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (::std::istream& is,
               const ::std::string& sid,
               ::xml_schema::error_handler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::Objects::objectList_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (::std::istream& is,
               const ::std::string& sid,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::Objects::objectList_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (::xercesc::InputSource& i,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
  {
    ::xsd::cxx::tree::error_handler< char > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (
        i, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

    return ::std::unique_ptr< ::Objects::objectList > (
      ::Objects::objectList_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (::xercesc::InputSource& i,
               ::xml_schema::error_handler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< char > ();

    return ::std::unique_ptr< ::Objects::objectList > (
      ::Objects::objectList_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (::xercesc::InputSource& i,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< char > ();

    return ::std::unique_ptr< ::Objects::objectList > (
      ::Objects::objectList_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (const ::xercesc::DOMDocument& doc,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

      return ::std::unique_ptr< ::Objects::objectList > (
        ::Objects::objectList_ (
          std::move (d), f | ::xml_schema::flags::own_dom, p));
    }

    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (e));

    if (n.name () == "objectList" &&
        n.namespace_ () == "Objects")
    {
      ::std::unique_ptr< ::Objects::objectList > r (
        ::xsd::cxx::tree::traits< ::Objects::objectList, char >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < char > (
      n.name (),
      n.namespace_ (),
      "objectList",
      "Objects");
  }

  ::std::unique_ptr< ::Objects::objectList >
  objectList_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

    if (n.name () == "objectList" &&
        n.namespace_ () == "Objects")
    {
      ::std::unique_ptr< ::Objects::objectList > r (
        ::xsd::cxx::tree::traits< ::Objects::objectList, char >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < char > (
      n.name (),
      n.namespace_ (),
      "objectList",
      "Objects");
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

