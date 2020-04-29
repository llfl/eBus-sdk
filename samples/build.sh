SAMPLES=" \
  DeviceFinder \
  GenICamParameters \
  MulticastMaster \
  MulticastSlave \
  MultiSource \
  PvPipelineSample \
  PvStreamSample \
  DeviceSerialPort \
  TransmitTestPattern \
  ConnectionRecovery \
  TapReconstruction \
  TransmitChunkData \
  ConfigurationReader \
  CameraBridge \
  eBUSPlayer \
  eBUSPlayer \
  DualSource \
  TransmitProcessedImage \
  ImageProcessing \
"

for SAMPLE in $SAMPLES; do
  make -C $SAMPLE
done

