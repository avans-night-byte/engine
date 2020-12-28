for f in ./Resources/XML/Schemas/*.xsd
do 
				xsdcxx cxx-tree --std c++11 --generate-doxygen --output-dir "Resources/XML/Generated" $f
done
