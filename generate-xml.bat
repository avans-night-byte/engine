for %%f in (Resources\XML\Schemas\*.xsd) do (Libraries\XSD\bin\xsd.exe cxx-tree --std c++11 --output-dir Resources\XML\Generated %%f)