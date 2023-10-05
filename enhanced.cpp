class Enhanced : public Packet
{
private:
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

  string getProtocolVersion()
  {
    return protocolVersion;
  }

  void setProtocolVersion(string protocolVersion)
  {
    this->protocolVersion = protocolVersion;
  }

  string getConcatIndicator()
  {
    return concatIndicator;
  }

  void setConcatIndicator(string concatIndicator)
  {
    this->concatIndicator = concatIndicator;
  }

  string getMessageType()
  {
    return messageType;
  }

  void setMessageType(string messageType)
  {
    this->messageType = messageType;
  }

  string getPayloadSize()
  {
    return payloadSize;
  }

  void setPayloadSize(string payloadSize)
  {
    this->payloadSize = payloadSize;
  }

  string getRtcId()
  {
    return rtcId;
  }

  void setRtcId(string rtcId)
  {
    this->rtcId = rtcId;
  }

  string getSequenceId()
  {
    return sequenceId;
  }

  void setSequenceId(string sequenceId)
  {
    this->sequenceId = sequenceId;
  }

  void printPacketInfo(int n, ofstream &outputFile)
  {
    Packet::printPacketInfo(n, outputFile);
    outputFile << "Concatenation Indicator: " << concatIndicator << endl;
    outputFile << "Destination Address: " << getDestinationAddress() << endl;
    outputFile << "Message Type: " << messageType << endl;
    outputFile << "Payload Size: " << payloadSize << endl;
    outputFile << "Protocol Version: " << protocolVersion << endl;
    outputFile << "RTC ID: " << rtcId << endl;
    outputFile << "Sequence ID: " << sequenceId << endl;
    outputFile << "Source Address: " << getSourceAddress() << endl;
    outputFile << "Type: " << getType() << endl;
    outputFile << endl
               << "**************************************************************************************************************************************************************************************************************************************" << endl
               << endl;
  }
};
