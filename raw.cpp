class Raw : public Packet
{
public:
  Raw(string s) : Packet::Packet(s)
  {
  }

  void printPacketInfo(int n, ofstream &outputFile)
  {
    Packet::printPacketInfo(n, outputFile);
    outputFile << "Destination Address: " << getDestinationAddress() << endl;
    outputFile << "Source Address: " << getSourceAddress() << endl;
    outputFile << "Type: " << getType() << endl;
    outputFile << endl
               << "**************************************************************************************************************************************************************************************************************************************" << endl
               << endl;
  }
};
