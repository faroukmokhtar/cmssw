#ifndef CSCDigi_CSCCorrelatedLCTDigi_h
#define CSCDigi_CSCCorrelatedLCTDigi_h

/**\class CSCCorrelatedLCTDigi
 *
 * Digi for Correlated LCT trigger primitives. 
 *
 * $Date: 2006/05/18 19:59:33 $
 * $Revision: 1.6 $
 *
 * \author L. Gray, UF
 */

#include <boost/cstdint.hpp>

class CSCCorrelatedLCTDigi 
{
 public:
  
  /// Constructors
  CSCCorrelatedLCTDigi(const int trknmb, const int valid, const int quality, /// from values
		       const int keywire, const int strip, const int clct_pattern, /// clct pattern is 4 bit pattern! 
		       const int bend, const int bx);                        /// (pattern) | (strip_type << 3) 

  CSCCorrelatedLCTDigi();                               /// default

  /// clear this LCT
  void clear();

  /// return track number
  int getTrknmb()  const { return trknmb; }

  /// return valid pattern bit
  bool isValid()   const { return valid; }

  /// return the 4 bit Correlated LCT Quality
  int getQuality() const { return quality; }

  /// return the key wire group
  int getKeyWG()   const { return keywire; }

  /// return the strip
  int getStrip()   const { return strip; }

  /// return pattern
  int getPattern() const { return pattern; }

  /// return bend
  int getBend()   const  { return bend; }

  /// return BX
  int getBX()     const { return bx; }

  /// return CLCT pattern number
  int getCLCTPattern() const { return (pattern & 0x7); }

  /// return strip type
  int getStripType() const   { return ((pattern & 0x8) >> 3); }

  /// Set track number (1,2) after sorting LCTs.
  void setTrknmb(const uint16_t number) {trknmb = number;}

  /// Print content of correlated LCT digi
  void print() const;

  ///Comparison
  bool operator == (const CSCCorrelatedLCTDigi &) const;
  bool operator != (const CSCCorrelatedLCTDigi &rhs) const
    { return !(this->operator==(rhs)); }

 private:

  friend class testCSCDigis;
  uint16_t valid;
  uint16_t quality;
  uint16_t keywire;
  uint16_t strip;
  uint16_t pattern;
  uint16_t bend;
  uint16_t bx;
  uint16_t trknmb;
};

#include<iostream>
inline std::ostream & operator<<(std::ostream & o,
				 const CSCCorrelatedLCTDigi& digi) {
  return o << "CSC LCT #"   << digi.getTrknmb()
	   << ": Valid = "  << digi.isValid()
	   << " Quality = " << digi.getQuality() << "\n"
	   <<"  cathode info: Strip = "    << digi.getStrip()
	   <<" ("           << ((digi.getStripType() == 0) ? 'D' : 'H') << ")"
	   << " Bend = "    << ((digi.getBend() == 0) ? 'L' : 'R')
	   << " Pattern = " << digi.getCLCTPattern() << "\n"
 	   <<"    anode info: Key wire = " << digi.getKeyWG()
	   << " BX = "      << digi.getBX() << "\n";
}
#endif
