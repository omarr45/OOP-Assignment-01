class Enhanced : public Packet
{
protected:
  string protocolVersion;
  string concatIndicator;
  string messageType;
  string payloadSize;
  string rtcId;
  string sequenceId;

public:
  Enhanced(string s) : Packet::Packet(s)
  {
    protocolVersion = s.substr(44, 1);
    concatIndicator = s.substr(45, 1);
    messageType = s.substr(46, 2);
    payloadSize = s.substr(48, 4);
    rtcId = s.substr(52, 4);
    sequenceId = s.substr(56, 4);
  }
  void printPacketInfo(int n, ofstream &outputFile)
  {
    Packet::printPacketInfo(n, outputFile);
    outputFile << "Concatenation Indicator: " << concatIndicator << endl;
    outputFile << "Destination Address: " << destinationAddress << endl;
    outputFile << "Message Type: " << messageType << endl;
    outputFile << "Payload Size: " << payloadSize << endl;
    outputFile << "Protocol Version: " << protocolVersion << endl;
    outputFile << "RTC ID: " << rtcId << endl;
    outputFile << "Sequence ID: " << sequenceId << endl;
    outputFile << "Source Address: " << sourceAddress << endl;
    outputFile << "Type: " << type << endl;
    outputFile << endl
               << "**************************************************************************************************************************************************************************************************************************************" << endl
               << endl;
  }
};
