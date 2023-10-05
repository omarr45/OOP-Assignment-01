#include <iostream>

using namespace std;

class Packet
{
private:
  string line;
  string crc;
  string destinationAddress;
  string sourceAddress;
  string type;

  const int destinationAddressStart = 16;
  const int destinationAddressEnd = 28;
  const int sourceAddressStart = 28;
  const int sourceAddressEnd = 40;
  const int typeStart = 40;
  const int typeEnd = 44;
  const int crcSize = 8;

public:
  Packet(string s)
  {
    line = s;
    crc = s.substr(s.length() - crcSize, crcSize);
    destinationAddress = s.substr(destinationAddressStart, destinationAddressEnd - destinationAddressStart);
    sourceAddress = s.substr(sourceAddressStart, sourceAddressEnd - sourceAddressStart);
    type = s.substr(typeStart, typeEnd - typeStart);
  }

  string getLine()
  {
    return line;
  }

  void setLine(string line)
  {
    this->line = line;
  }

  string getCrc()
  {
    return crc;
  }

  void setCrc(string crc)
  {
    this->crc = crc;
  }

  string getDestinationAddress()
  {
    return destinationAddress;
  }

  void setDestinationAddress(string destinationAddress)
  {
    this->destinationAddress = destinationAddress;
  }

  string getSourceAddress()
  {
    return sourceAddress;
  }

  void setSourceAddress(string sourceAddress)
  {
    this->sourceAddress = sourceAddress;
  }

  string getType()
  {
    return type;
  }

  void setType(string type)
  {
    this->type = type;
  }

  virtual void printPacketInfo(int idx, ofstream &outputFile)
  {
    outputFile << "Packet # " << idx << ":" << endl;
    outputFile << line << endl;
    outputFile << "CRC: " << crc << endl;
  }
};