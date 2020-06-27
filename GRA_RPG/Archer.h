#pragma once
#include "Champion.h"

///Class Archer Inherits a champion
///Class Archer Inherits a champion.
class Archer : public Champion {
public:
   /// Constructor Archer cause a champion constructor.
   /// <param name="write"> - The inscription that will be shown on the button </param>
   /// <param name="id"> - Id champion in database</param>
   /// <param name="n"> - Name champion</param>
   /// <param name="l"> - Level champion</param>
   /// <param name="e"> - Experience champion  </param>
   /// <param name="m"> - Money champion </param>
   /// <param name="he"> - Health champion </param>
   /// <param name="st"> - Strength champion </param>
   /// <param name="de"> - Dexerity Champion</param>
   /// <param name="ma"> - Magic champion </param>
   /// <param name="def"> - Defence champion </param>
   /// <param name="lu"> - Lucky champion </param>
	///Constructor Archer cause a champion constructor
	/// <param name="write"> - The inscription that will be shown on the button </param>     
	/// <param name="id"> - Id champion in database</param>    
	/// <param name="n"> - Name champion</param>    
	/// <param name="l"> - Level champion</param>    
	/// <param name="e"> - Experience champion  </param>    
	/// <param name="m"> - Money champion </param>    
	/// <param name="he"> - Health champion </param>  
	/// <param name="st"> - Strength champion </param>  
	/// <param name="de"> - Dexerity Champion</param>  
	/// <param name="ma"> - Magic champion </param>  
	/// <param name="def"> - Defence champion </param>  
	/// <param name="lu"> - Lucky champion </param>  
	Archer(const unsigned id, const std::string n, unsigned int l, unsigned int e, double m, int he, int st, int de, int ma, int def, int lu) :
		Champion(id, n, l, e, m, he, st, de, ma, def, lu) {}

	/// Virtual function attack.
	/// <returns> value attack </returns>
	virtual int attack() override;
	///Virtual function block
	///<returns> value block </returns> 
	/// Virtual function block.
	/// <returns> value block </returns> 
	virtual int block() override;

	///Virtual function clone to clone object
	///<returns> Pointer object Archer </returns> 
	/// Virtual function clone to clone object.
	/// <returns> Pointer object Archer </returns> 
	virtual Archer* clone() const
	{
		return new Archer(*this);
	}
};