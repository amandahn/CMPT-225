/*
 * Dictionary.cpp
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 * 
 * Author: Amanda Ngo
 * Date: March 10, 2022
 */
 
 #include "Dictionary.h"
    // Constructors and destructor:

    // Default constructor
    template<class ElementType>
    Dictionary<ElementType>::Dictionary(){
        keyValuePairs = new BST<ElementType>();
    }

    // Paramaterized constructor
    template<class ElementType>                       
    Dictionary<ElementType>::Dictionary(ElementType& element){
        keyValuePairs->insert(element);
    }    
    
    // Destructor 
    template<class ElementType>                       
    Dictionary<ElementType>:: ~Dictionary(){
        if(keyValuePairs->getElementCount() > 0){
            delete keyValuePairs;
        }
    }   

    // Dictionary operations:

    // Description: Returns the elementCount value of keyValuePairs
    template<class ElementType>  
	unsigned int Dictionary<ElementType>::getElementCount() const{
        return keyValuePairs->getElementCount();
    }
	
	// Description: Puts "newElement" into the dictionary.
	// Precondition: Conditions listed in "BST.cpp" for the insert operation
    template<class ElementType>  
	void Dictionary<ElementType>::put(const ElementType& newElement){
        keyValuePairs->insert(newElement);
    }

	// Description: Gets "targetElement" from the dictionary.
	// Precondition: Conditions listed in "BST.cpp" for the retrieve operation
    template<class ElementType>  
	ElementType& Dictionary<ElementType>::get(const ElementType& targetElement) const{
        return keyValuePairs->retrieve(targetElement);
    }

    // Description: Displays the content of keyValuePairs
    // Precondition: Conditions listed in "BST.cpp" for the traverseInOrder operation
    template<class ElementType>  
    void Dictionary<ElementType>::displayContent(void visit(const ElementType&)) const{
        keyValuePairs->traverseInOrder(visit);
    }
