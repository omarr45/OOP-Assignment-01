class Raw : public Packet
{
public:
  Raw(string s) : Packet::Packet(s)
  {
  }
  void printPacketInfo(int n, ofstream &outputFile)
  {
    Packet::printPacketInfo(n, outputFile);
    outputFile << "Destination Address: " << destinationAddress << endl;
    outputFile << "Source Address: " << sourceAddress << endl;
    outputFile << "Type: " << type << endl;
    outputFile << endl
               << "**************************************************************************************************************************************************************************************************************************************" << endl
               << endl;
  }
};
