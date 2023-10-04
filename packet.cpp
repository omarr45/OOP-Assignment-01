#include <iostream>

using namespace std;

class Packet
{
protected:
  string line;
  string preamble;
  string crc;
  string destinationAddress;
  string sourceAddress;
  string type;

public:
  Packet()
  {
  }
  Packet(string s)
  {
    line = s;
    crc = s.substr(s.length() - 8, 8);
    preamble = s.substr(0, 16);
    destinationAddress = s.substr(16, 12);
    sourceAddress = s.substr(28, 12);
    type = s.substr(40, 4);
  }
  virtual void printPacketInfo(int idx, ofstream &outputFile)
  {
    outputFile << "Packet # " << idx << ":" << endl;
    outputFile << line << endl;
    outputFile << "CRC: " << crc << endl;
  }
};