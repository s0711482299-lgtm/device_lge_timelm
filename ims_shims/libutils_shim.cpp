#include <cstdint>
#include <android/log.h>

namespace {
  void log_first(const char* name) {
    static bool once = false;
    if (!once) { once = true;
      __android_log_print(ANDROID_LOG_INFO, "ims-shim", "STUB: %s", name);
    }
  }
}

// android::BufferItem::BufferItem()
extern "C" uintptr_t _ZN7android10BufferItemC1Ev(void) {
  log_first("_ZN7android10BufferItemC1Ev");
  return 0;
}

// android::BufferItem::~BufferItem()
extern "C" uintptr_t _ZN7android10BufferItemD1Ev(void) {
  log_first("_ZN7android10BufferItemD1Ev");
  return 0;
}

// android::AudioSystem::setParameters(int, android::String8 const&)
extern "C" uintptr_t _ZN7android11AudioSystem13setParametersEiRKNS_7String8E(void) {
  log_first("_ZN7android11AudioSystem13setParametersEiRKNS_7String8E");
  return 0;
}

// android::BufferQueue::createBufferQueue(android::sp<android::IGraphicBufferProducer>*, android::sp<android::IGraphicBufferConsumer>*, bool)
extern "C" uintptr_t _ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEEb(void) {
  log_first("_ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEEb");
  return 0;
}

// android::ConsumerBase::setFrameAvailableListener(android::wp<android::ConsumerBase::FrameAvailableListener> const&)
extern "C" uintptr_t _ZN7android12ConsumerBase25setFrameAvailableListenerERKNS_2wpINS0_22FrameAvailableListenerEEE(void) {
  log_first("_ZN7android12ConsumerBase25setFrameAvailableListenerERKNS_2wpINS0_22FrameAvailableListenerEEE");
  return 0;
}

// android::ConsumerBase::setName(android::String8 const&)
extern "C" uintptr_t _ZN7android12ConsumerBase7setNameERKNS_7String8E(void) {
  log_first("_ZN7android12ConsumerBase7setNameERKNS_7String8E");
  return 0;
}

// android::IOMXObserver::descriptor
extern "C" uintptr_t _ZN7android12IOMXObserver10descriptorE(void) {
  log_first("_ZN7android12IOMXObserver10descriptorE");
  return 0;
}

// android::IOMXObserver::IOMXObserver()
extern "C" uintptr_t _ZN7android12IOMXObserverC2Ev(void) {
  log_first("_ZN7android12IOMXObserverC2Ev");
  return 0;
}

// android::IOMXObserver::~IOMXObserver()
extern "C" uintptr_t _ZN7android12IOMXObserverD0Ev(void) {
  log_first("_ZN7android12IOMXObserverD0Ev");
  return 0;
}

// android::IOMXObserver::~IOMXObserver()
extern "C" uintptr_t _ZN7android12IOMXObserverD1Ev(void) {
  log_first("_ZN7android12IOMXObserverD1Ev");
  return 0;
}

// android::IOMXObserver::~IOMXObserver()
extern "C" uintptr_t _ZN7android12IOMXObserverD2Ev(void) {
  log_first("_ZN7android12IOMXObserverD2Ev");
  return 0;
}

// android::SecureBuffer::SecureBuffer(android::sp<android::AMessage> const&, void const*, unsigned long)
extern "C" uintptr_t _ZN7android12SecureBufferC1ERKNS_2spINS_8AMessageEEEPKvm(void) {
  log_first("_ZN7android12SecureBufferC1ERKNS_2spINS_8AMessageEEEPKvm");
  return 0;
}

// android::SecureBuffer::SecureBuffer(android::sp<android::AMessage> const&, android::sp<android::NativeHandle> const&, unsigned long)
extern "C" uintptr_t _ZN7android12SecureBufferC1ERKNS_2spINS_8AMessageEEERKNS1_INS_12NativeHandleEEEm(void) {
  log_first("_ZN7android12SecureBufferC1ERKNS_2spINS_8AMessageEEERKNS1_INS_12NativeHandleEEEm");
  return 0;
}

// android::BnOMXObserver::onTransact(unsigned int, android::Parcel const&, android::Parcel*, unsigned int)
extern "C" uintptr_t _ZN7android13BnOMXObserver10onTransactEjRKNS_6ParcelEPS1_j(void) {
  log_first("_ZN7android13BnOMXObserver10onTransactEjRKNS_6ParcelEPS1_j");
  return 0;
}

// android::GraphicBuffer::lock(unsigned int, void**, int*, int*)
extern "C" uintptr_t _ZN7android13GraphicBuffer4lockEjPPvPiS3_(void) {
  log_first("_ZN7android13GraphicBuffer4lockEjPPvPiS3_");
  return 0;
}

// android::GraphicBuffer::unlock()
extern "C" uintptr_t _ZN7android13GraphicBuffer6unlockEv(void) {
  log_first("_ZN7android13GraphicBuffer6unlockEv");
  return 0;
}

// android::MediaCodecList::getInstance()
extern "C" uintptr_t _ZN7android14MediaCodecList11getInstanceEv(void) {
  log_first("_ZN7android14MediaCodecList11getInstanceEv");
  return 0;
}

// android::BufferItemConsumer::acquireBuffer(android::BufferItem*, long, bool)
extern "C" uintptr_t _ZN7android18BufferItemConsumer13acquireBufferEPNS_10BufferItemElb(void) {
  log_first("_ZN7android18BufferItemConsumer13acquireBufferEPNS_10BufferItemElb");
  return 0;
}

// android::BufferItemConsumer::releaseBuffer(android::BufferItem const&, android::sp<android::Fence> const&)
extern "C" uintptr_t _ZN7android18BufferItemConsumer13releaseBufferERKNS_10BufferItemERKNS_2spINS_5FenceEEE(void) {
  log_first("_ZN7android18BufferItemConsumer13releaseBufferERKNS_10BufferItemERKNS_2spINS_5FenceEEE");
  return 0;
}

// android::BufferItemConsumer::BufferItemConsumer(android::sp<android::IGraphicBufferConsumer> const&, unsigned long, int, bool)
extern "C" uintptr_t _ZN7android18BufferItemConsumerC1ERKNS_2spINS_22IGraphicBufferConsumerEEEmib(void) {
  log_first("_ZN7android18BufferItemConsumerC1ERKNS_2spINS_22IGraphicBufferConsumerEEEmib");
  return 0;
}

// android::SharedMemoryBuffer::SharedMemoryBuffer(android::sp<android::AMessage> const&, android::sp<android::hidl::memory::V1_0::IMemory> const&)
extern "C" uintptr_t _ZN7android18SharedMemoryBufferC1ERKNS_2spINS_8AMessageEEERKNS1_INS_4hidl6memory4V1_07IMemoryEEE(void) {
  log_first("_ZN7android18SharedMemoryBufferC1ERKNS_2spINS_8AMessageEEERKNS1_INS_4hidl6memory4V1_07IMemoryEEE");
  return 0;
}

// android::SharedMemoryBuffer::SharedMemoryBuffer(android::sp<android::AMessage> const&, android::sp<android::IMemory> const&)
extern "C" uintptr_t _ZN7android18SharedMemoryBufferC1ERKNS_2spINS_8AMessageEEERKNS1_INS_7IMemoryEEE(void) {
  log_first("_ZN7android18SharedMemoryBufferC1ERKNS_2spINS_8AMessageEEERKNS1_INS_7IMemoryEEE");
  return 0;
}

// android::GraphicBufferMapper::lock(native_handle const*, unsigned int, android::Rect const&, void**, int*, int*)
extern "C" uintptr_t _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPvPiS9_(void) {
  log_first("_ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPvPiS9_");
  return 0;
}

// android::GraphicBufferMapper::unlock(native_handle const*)
extern "C" uintptr_t _ZN7android19GraphicBufferMapper6unlockEPK13native_handle(void) {
  log_first("_ZN7android19GraphicBufferMapper6unlockEPK13native_handle");
  return 0;
}

// android::GraphicBufferMapper::GraphicBufferMapper()
extern "C" uintptr_t _ZN7android19GraphicBufferMapperC1Ev(void) {
  log_first("_ZN7android19GraphicBufferMapperC1Ev");
  return 0;
}

// android::IGraphicBufferProducer::asInterface(android::sp<android::IBinder> const&)
extern "C" uintptr_t _ZN7android22IGraphicBufferProducer11asInterfaceERKNS_2spINS_7IBinderEEE(void) {
  log_first("_ZN7android22IGraphicBufferProducer11asInterfaceERKNS_2spINS_7IBinderEEE");
  return 0;
}

// android::hidl::base::V1_0::IBase::linkToDeath(android::sp<android::hardware::hidl_death_recipient> const&, unsigned long)
extern "C" uintptr_t _ZN7android4hidl4base4V1_05IBase11linkToDeathERKNS_2spINS_8hardware20hidl_death_recipientEEEm(void) {
  log_first("_ZN7android4hidl4base4V1_05IBase11linkToDeathERKNS_2spINS_8hardware20hidl_death_recipientEEEm");
  return 0;
}

// android::hidl::base::V1_0::IBase::getDebugInfo(std::__1::function<void (android::hidl::base::V1_0::DebugInfo const&)>)
extern "C" uintptr_t _ZN7android4hidl4base4V1_05IBase12getDebugInfoENSt3__18functionIFvRKNS2_9DebugInfoEEEE(void) {
  log_first("_ZN7android4hidl4base4V1_05IBase12getDebugInfoENSt3__18functionIFvRKNS2_9DebugInfoEEEE");
  return 0;
}

// android::hidl::base::V1_0::IBase::getHashChain(std::__1::function<void (android::hardware::hidl_vec<android::hardware::hidl_array<unsigned char, 32ul> > const&)>)
extern "C" uintptr_t _ZN7android4hidl4base4V1_05IBase12getHashChainENSt3__18functionIFvRKNS_8hardware8hidl_vecINS6_10hidl_arrayIhLm32EJEEEEEEEE(void) {
  log_first("_ZN7android4hidl4base4V1_05IBase12getHashChainENSt3__18functionIFvRKNS_8hardware8hidl_vecINS6_10hidl_arrayIhLm32EJEEEEEEEE");
  return 0;
}

// android::hidl::base::V1_0::IBase::unlinkToDeath(android::sp<android::hardware::hidl_death_recipient> const&)
extern "C" uintptr_t _ZN7android4hidl4base4V1_05IBase13unlinkToDeathERKNS_2spINS_8hardware20hidl_death_recipientEEE(void) {
  log_first("_ZN7android4hidl4base4V1_05IBase13unlinkToDeathERKNS_2spINS_8hardware20hidl_death_recipientEEE");
  return 0;
}

// android::hidl::base::V1_0::IBase::interfaceChain(std::__1::function<void (android::hardware::hidl_vec<android::hardware::hidl_string> const&)>)
extern "C" uintptr_t _ZN7android4hidl4base4V1_05IBase14interfaceChainENSt3__18functionIFvRKNS_8hardware8hidl_vecINS6_11hidl_stringEEEEEE(void) {
  log_first("_ZN7android4hidl4base4V1_05IBase14interfaceChainENSt3__18functionIFvRKNS_8hardware8hidl_vecINS6_11hidl_stringEEEEEE");
  return 0;
}

// android::hidl::base::V1_0::IBase::interfaceDescriptor(std::__1::function<void (android::hardware::hidl_string const&)>)
extern "C" uintptr_t _ZN7android4hidl4base4V1_05IBase19interfaceDescriptorENSt3__18functionIFvRKNS_8hardware11hidl_stringEEEE(void) {
  log_first("_ZN7android4hidl4base4V1_05IBase19interfaceDescriptorENSt3__18functionIFvRKNS_8hardware11hidl_stringEEEE");
  return 0;
}

// android::hidl::base::V1_0::IBase::notifySyspropsChanged()
extern "C" uintptr_t _ZN7android4hidl4base4V1_05IBase21notifySyspropsChangedEv(void) {
  log_first("_ZN7android4hidl4base4V1_05IBase21notifySyspropsChangedEv");
  return 0;
}

// android::hidl::base::V1_0::IBase::setHALInstrumentation()
extern "C" uintptr_t _ZN7android4hidl4base4V1_05IBase21setHALInstrumentationEv(void) {
  log_first("_ZN7android4hidl4base4V1_05IBase21setHALInstrumentationEv");
  return 0;
}

// android::hidl::base::V1_0::IBase::ping()
extern "C" uintptr_t _ZN7android4hidl4base4V1_05IBase4pingEv(void) {
  log_first("_ZN7android4hidl4base4V1_05IBase4pingEv");
  return 0;
}

// android::hidl::base::V1_0::IBase::debug(android::hardware::hidl_handle const&, android::hardware::hidl_vec<android::hardware::hidl_string> const&)
extern "C" uintptr_t _ZN7android4hidl4base4V1_05IBase5debugERKNS_8hardware11hidl_handleERKNS4_8hidl_vecINS4_11hidl_stringEEE(void) {
  log_first("_ZN7android4hidl4base4V1_05IBase5debugERKNS_8hardware11hidl_handleERKNS4_8hidl_vecINS4_11hidl_stringEEE");
  return 0;
}

// android::hidl::allocator::V1_0::IAllocator::getService(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, bool)
extern "C" uintptr_t _ZN7android4hidl9allocator4V1_010IAllocator10getServiceERKNSt3__112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEb(void) {
  log_first("_ZN7android4hidl9allocator4V1_010IAllocator10getServiceERKNSt3__112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEb");
  return 0;
}

// android::Fence::NO_FENCE
extern "C" uintptr_t _ZN7android5Fence8NO_FENCEE(void) {
  log_first("_ZN7android5Fence8NO_FENCEE");
  return 0;
}

// android::Region::operator=(android::Region const&)
extern "C" uintptr_t _ZN7android6RegionaSERKS0_(void) {
  log_first("_ZN7android6RegionaSERKS0_");
  return 0;
}

// android::Surface::Surface(android::sp<android::IGraphicBufferProducer> const&, bool, android::sp<android::IBinder> const&)
extern "C" uintptr_t _ZN7android7SurfaceC1ERKNS_2spINS_22IGraphicBufferProducerEEEbRKNS1_INS_7IBinderEEE(void) {
  log_first("_ZN7android7SurfaceC1ERKNS_2spINS_22IGraphicBufferProducerEEEbRKNS1_INS_7IBinderEEE");
  return 0;
}

// android::hardware::hidl_handle::operator=(android::hardware::hidl_handle const&)
extern "C" uintptr_t _ZN7android8hardware11hidl_handleaSERKS1_(void) {
  log_first("_ZN7android8hardware11hidl_handleaSERKS1_");
  return 0;
}

// android::hardware::hidl_handle::hidl_handle(native_handle const*)
extern "C" uintptr_t _ZN7android8hardware11hidl_handleC1EPK13native_handle(void) {
  log_first("_ZN7android8hardware11hidl_handleC1EPK13native_handle");
  return 0;
}

// android::hardware::hidl_handle::~hidl_handle()
extern "C" uintptr_t _ZN7android8hardware11hidl_handleD1Ev(void) {
  log_first("_ZN7android8hardware11hidl_handleD1Ev");
  return 0;
}

// android::hardware::hidl_string::operator=(android::hardware::hidl_string const&)
extern "C" uintptr_t _ZN7android8hardware11hidl_stringaSERKS1_(void) {
  log_first("_ZN7android8hardware11hidl_stringaSERKS1_");
  return 0;
}

// android::hardware::hidl_string::hidl_string(char const*)
extern "C" uintptr_t _ZN7android8hardware11hidl_stringC1EPKc(void) {
  log_first("_ZN7android8hardware11hidl_stringC1EPKc");
  return 0;
}

// android::hardware::hidl_string::hidl_string(char const*, unsigned long)
extern "C" uintptr_t _ZN7android8hardware11hidl_stringC1EPKcm(void) {
  log_first("_ZN7android8hardware11hidl_stringC1EPKcm");
  return 0;
}

// android::hardware::hidl_string::~hidl_string()
extern "C" uintptr_t _ZN7android8hardware11hidl_stringD1Ev(void) {
  log_first("_ZN7android8hardware11hidl_stringD1Ev");
  return 0;
}

// android::hardware::details::return_status::operator=(android::hardware::details::return_status&&)
extern "C" uintptr_t _ZN7android8hardware7details13return_statusaSEOS2_(void) {
  log_first("_ZN7android8hardware7details13return_statusaSEOS2_");
  return 0;
}

// android::hardware::details::return_status::~return_status()
extern "C" uintptr_t _ZN7android8hardware7details13return_statusD2Ev(void) {
  log_first("_ZN7android8hardware7details13return_statusD2Ev");
  return 0;
}

// android::hardware::mapMemory(android::hardware::hidl_memory const&)
extern "C" uintptr_t _ZN7android8hardware9mapMemoryERKNS0_11hidl_memoryE(void) {
  log_first("_ZN7android8hardware9mapMemoryERKNS0_11hidl_memoryE");
  return 0;
}

// android::OMXBuffer::sPreset
extern "C" uintptr_t _ZN7android9OMXBuffer7sPresetE(void) {
  log_first("_ZN7android9OMXBuffer7sPresetE");
  return 0;
}

// android::OMXBuffer::OMXBuffer(android::sp<android::GraphicBuffer> const&)
extern "C" uintptr_t _ZN7android9OMXBufferC1ERKNS_2spINS_13GraphicBufferEEE(void) {
  log_first("_ZN7android9OMXBufferC1ERKNS_2spINS_13GraphicBufferEEE");
  return 0;
}

// android::OMXBuffer::OMXBuffer(android::sp<android::MediaCodecBuffer> const&)
extern "C" uintptr_t _ZN7android9OMXBufferC1ERKNS_2spINS_16MediaCodecBufferEEE(void) {
  log_first("_ZN7android9OMXBufferC1ERKNS_2spINS_16MediaCodecBufferEEE");
  return 0;
}

// android::OMXBuffer::OMXBuffer(android::sp<android::IMemory> const&)
extern "C" uintptr_t _ZN7android9OMXBufferC1ERKNS_2spINS_7IMemoryEEE(void) {
  log_first("_ZN7android9OMXBufferC1ERKNS_2spINS_7IMemoryEEE");
  return 0;
}

// android::OMXBuffer::OMXBuffer(android::hardware::hidl_memory const&)
extern "C" uintptr_t _ZN7android9OMXBufferC1ERKNS_8hardware11hidl_memoryE(void) {
  log_first("_ZN7android9OMXBufferC1ERKNS_8hardware11hidl_memoryE");
  return 0;
}

// android::OMXBuffer::~OMXBuffer()
extern "C" uintptr_t _ZN7android9OMXBufferD1Ev(void) {
  log_first("_ZN7android9OMXBufferD1Ev");
  return 0;
}

// android::OMXClient::disconnect()
extern "C" uintptr_t _ZN7android9OMXClient10disconnectEv(void) {
  log_first("_ZN7android9OMXClient10disconnectEv");
  return 0;
}

// android::OMXClient::connect()
extern "C" uintptr_t _ZN7android9OMXClient7connectEv(void) {
  log_first("_ZN7android9OMXClient7connectEv");
  return 0;
}

// android::OMXClient::interface()
extern "C" uintptr_t _ZN7android9OMXClient9interfaceEv(void) {
  log_first("_ZN7android9OMXClient9interfaceEv");
  return 0;
}

// android::OMXClient::OMXClient()
extern "C" uintptr_t _ZN7android9OMXClientC1Ev(void) {
  log_first("_ZN7android9OMXClientC1Ev");
  return 0;
}

// android::Singleton<android::GraphicBufferMapper>::sLock
extern "C" uintptr_t _ZN7android9SingletonINS_19GraphicBufferMapperEE5sLockE(void) {
  log_first("_ZN7android9SingletonINS_19GraphicBufferMapperEE5sLockE");
  return 0;
}

// android::Singleton<android::GraphicBufferMapper>::sInstance
extern "C" uintptr_t _ZN7android9SingletonINS_19GraphicBufferMapperEE9sInstanceE(void) {
  log_first("_ZN7android9SingletonINS_19GraphicBufferMapperEE9sInstanceE");
  return 0;
}

// android::IOMXObserver::getInterfaceDescriptor() const
extern "C" uintptr_t _ZNK7android12IOMXObserver22getInterfaceDescriptorEv(void) {
  log_first("_ZNK7android12IOMXObserver22getInterfaceDescriptorEv");
  return 0;
}

// android::String8::getPathLeaf() const
extern "C" uintptr_t _ZNK7android7String811getPathLeafEv(void) {
  log_first("_ZNK7android7String811getPathLeafEv");
  return 0;
}

// android::Surface::getIGraphicBufferProducer() const
extern "C" uintptr_t _ZNK7android7Surface25getIGraphicBufferProducerEv(void) {
  log_first("_ZNK7android7Surface25getIGraphicBufferProducerEv");
  return 0;
}

// android::hardware::hidl_string::c_str() const
extern "C" uintptr_t _ZNK7android8hardware11hidl_string5c_strEv(void) {
  log_first("_ZNK7android8hardware11hidl_string5c_strEv");
  return 0;
}

// android::hardware::Status::description() const
extern "C" uintptr_t _ZNK7android8hardware6Status11descriptionEv(void) {
  log_first("_ZNK7android8hardware6Status11descriptionEv");
  return 0;
}

// android::hardware::details::return_status::onValueRetrieval() const
extern "C" uintptr_t _ZNK7android8hardware7details13return_status16onValueRetrievalEv(void) {
  log_first("_ZNK7android8hardware7details13return_status16onValueRetrievalEv");
  return 0;
}

// android::IInterface::asBinder(android::sp<android::IInterface> const&)
extern "C" uintptr_t _ZN7android10IInterface8asBinderERKNS_2spIS0_EE(void) {
  log_first("_ZN7android10IInterface8asBinderERKNS_2spIS0_EE");
  return 0;
}

// android::IInterface::IInterface()
extern "C" uintptr_t _ZN7android10IInterfaceC2Ev(void) {
  log_first("_ZN7android10IInterfaceC2Ev");
  return 0;
}

// android::IInterface::~IInterface()
extern "C" uintptr_t _ZN7android10IInterfaceD0Ev(void) {
  log_first("_ZN7android10IInterfaceD0Ev");
  return 0;
}

// android::IInterface::~IInterface()
extern "C" uintptr_t _ZN7android10IInterfaceD1Ev(void) {
  log_first("_ZN7android10IInterfaceD1Ev");
  return 0;
}

// android::IInterface::~IInterface()
extern "C" uintptr_t _ZN7android10IInterfaceD2Ev(void) {
  log_first("_ZN7android10IInterfaceD2Ev");
  return 0;
}

// android::MemoryDealer::getAllocationAlignment()
extern "C" uintptr_t _ZN7android12MemoryDealer22getAllocationAlignmentEv(void) {
  log_first("_ZN7android12MemoryDealer22getAllocationAlignmentEv");
  return 0;
}

// android::MemoryDealer::MemoryDealer(unsigned long, char const*, unsigned int)
extern "C" uintptr_t _ZN7android12MemoryDealerC1EmPKcj(void) {
  log_first("_ZN7android12MemoryDealerC1EmPKcj");
  return 0;
}

// android::IPCThreadState::self()
extern "C" uintptr_t _ZN7android14IPCThreadState4selfEv(void) {
  log_first("_ZN7android14IPCThreadState4selfEv");
  return 0;
}

// android::defaultServiceManager()
extern "C" uintptr_t _ZN7android21defaultServiceManagerEv(void) {
  log_first("_ZN7android21defaultServiceManagerEv");
  return 0;
}

// android::Parcel::writeInt32(int)
extern "C" uintptr_t _ZN7android6Parcel10writeInt32Ei(void) {
  log_first("_ZN7android6Parcel10writeInt32Ei");
  return 0;
}

// android::Parcel::writeInt64(long)
extern "C" uintptr_t _ZN7android6Parcel10writeInt64El(void) {
  log_first("_ZN7android6Parcel10writeInt64El");
  return 0;
}

// android::Parcel::writeString16(android::String16 const&)
extern "C" uintptr_t _ZN7android6Parcel13writeString16ERKNS_8String16E(void) {
  log_first("_ZN7android6Parcel13writeString16ERKNS_8String16E");
  return 0;
}

// android::Parcel::writeByteArray(unsigned long, unsigned char const*)
extern "C" uintptr_t _ZN7android6Parcel14writeByteArrayEmPKh(void) {
  log_first("_ZN7android6Parcel14writeByteArrayEmPKh");
  return 0;
}

// android::Parcel::writeStrongBinder(android::sp<android::IBinder> const&)
extern "C" uintptr_t _ZN7android6Parcel17writeStrongBinderERKNS_2spINS_7IBinderEEE(void) {
  log_first("_ZN7android6Parcel17writeStrongBinderERKNS_2spINS_7IBinderEEE");
  return 0;
}

// android::Parcel::writeInterfaceToken(android::String16 const&)
extern "C" uintptr_t _ZN7android6Parcel19writeInterfaceTokenERKNS_8String16E(void) {
  log_first("_ZN7android6Parcel19writeInterfaceTokenERKNS_8String16E");
  return 0;
}

// android::Parcel::write(void const*, unsigned long)
extern "C" uintptr_t _ZN7android6Parcel5writeEPKvm(void) {
  log_first("_ZN7android6Parcel5writeEPKvm");
  return 0;
}

// android::Parcel::setData(unsigned char const*, unsigned long)
extern "C" uintptr_t _ZN7android6Parcel7setDataEPKhm(void) {
  log_first("_ZN7android6Parcel7setDataEPKhm");
  return 0;
}

// android::Parcel::Parcel()
extern "C" uintptr_t _ZN7android6ParcelC1Ev(void) {
  log_first("_ZN7android6ParcelC1Ev");
  return 0;
}

// android::Parcel::~Parcel()
extern "C" uintptr_t _ZN7android6ParcelD1Ev(void) {
  log_first("_ZN7android6ParcelD1Ev");
  return 0;
}

// android::BBinder::onTransact(unsigned int, android::Parcel const&, android::Parcel*, unsigned int)
extern "C" uintptr_t _ZN7android7BBinder10onTransactEjRKNS_6ParcelEPS1_j(void) {
  log_first("_ZN7android7BBinder10onTransactEjRKNS_6ParcelEPS1_j");
  return 0;
}

// android::BBinder::pingBinder()
extern "C" uintptr_t _ZN7android7BBinder10pingBinderEv(void) {
  log_first("_ZN7android7BBinder10pingBinderEv");
  return 0;
}

// android::BBinder::linkToDeath(android::sp<android::IBinder::DeathRecipient> const&, void*, unsigned int)
extern "C" uintptr_t _ZN7android7BBinder11linkToDeathERKNS_2spINS_7IBinder14DeathRecipientEEEPvj(void) {
  log_first("_ZN7android7BBinder11linkToDeathERKNS_2spINS_7IBinder14DeathRecipientEEEPvj");
  return 0;
}

// android::BBinder::localBinder()
extern "C" uintptr_t _ZN7android7BBinder11localBinderEv(void) {
  log_first("_ZN7android7BBinder11localBinderEv");
  return 0;
}

// android::BBinder::attachObject(void const*, void*, void*, void (*)(void const*, void*, void*))
extern "C" uintptr_t _ZN7android7BBinder12attachObjectEPKvPvS3_PFvS2_S3_S3_E(void) {
  log_first("_ZN7android7BBinder12attachObjectEPKvPvS3_PFvS2_S3_S3_E");
  return 0;
}

// android::BBinder::detachObject(void const*)
extern "C" uintptr_t _ZN7android7BBinder12detachObjectEPKv(void) {
  log_first("_ZN7android7BBinder12detachObjectEPKv");
  return 0;
}

// android::BBinder::unlinkToDeath(android::wp<android::IBinder::DeathRecipient> const&, void*, unsigned int, android::wp<android::IBinder::DeathRecipient>*)
extern "C" uintptr_t _ZN7android7BBinder13unlinkToDeathERKNS_2wpINS_7IBinder14DeathRecipientEEEPvjPS4_(void) {
  log_first("_ZN7android7BBinder13unlinkToDeathERKNS_2wpINS_7IBinder14DeathRecipientEEEPvjPS4_");
  return 0;
}

// android::BBinder::dump(int, android::Vector<android::String16> const&)
extern "C" uintptr_t _ZN7android7BBinder4dumpEiRKNS_6VectorINS_8String16EEE(void) {
  log_first("_ZN7android7BBinder4dumpEiRKNS_6VectorINS_8String16EEE");
  return 0;
}

// android::BBinder::transact(unsigned int, android::Parcel const&, android::Parcel*, unsigned int)
extern "C" uintptr_t _ZN7android7BBinder8transactEjRKNS_6ParcelEPS1_j(void) {
  log_first("_ZN7android7BBinder8transactEjRKNS_6ParcelEPS1_j");
  return 0;
}

// android::BBinder::BBinder()
extern "C" uintptr_t _ZN7android7BBinderC2Ev(void) {
  log_first("_ZN7android7BBinderC2Ev");
  return 0;
}

// android::BBinder::~BBinder()
extern "C" uintptr_t _ZN7android7BBinderD0Ev(void) {
  log_first("_ZN7android7BBinderD0Ev");
  return 0;
}

// android::BBinder::~BBinder()
extern "C" uintptr_t _ZN7android7BBinderD1Ev(void) {
  log_first("_ZN7android7BBinderD1Ev");
  return 0;
}

// android::BBinder::~BBinder()
extern "C" uintptr_t _ZN7android7BBinderD2Ev(void) {
  log_first("_ZN7android7BBinderD2Ev");
  return 0;
}

// android::IBinder::localBinder()
extern "C" uintptr_t _ZN7android7IBinder11localBinderEv(void) {
  log_first("_ZN7android7IBinder11localBinderEv");
  return 0;
}

// android::IBinder::remoteBinder()
extern "C" uintptr_t _ZN7android7IBinder12remoteBinderEv(void) {
  log_first("_ZN7android7IBinder12remoteBinderEv");
  return 0;
}

// android::IBinder::queryLocalInterface(android::String16 const&)
extern "C" uintptr_t _ZN7android7IBinder19queryLocalInterfaceERKNS_8String16E(void) {
  log_first("_ZN7android7IBinder19queryLocalInterfaceERKNS_8String16E");
  return 0;
}

// android::IBinder::~IBinder()
extern "C" uintptr_t _ZN7android7IBinderD0Ev(void) {
  log_first("_ZN7android7IBinderD0Ev");
  return 0;
}

// android::IBinder::~IBinder()
extern "C" uintptr_t _ZN7android7IBinderD1Ev(void) {
  log_first("_ZN7android7IBinderD1Ev");
  return 0;
}

// android::BpRefBase::onFirstRef()
extern "C" uintptr_t _ZN7android9BpRefBase10onFirstRefEv(void) {
  log_first("_ZN7android9BpRefBase10onFirstRefEv");
  return 0;
}

// android::BpRefBase::onLastStrongRef(void const*)
extern "C" uintptr_t _ZN7android9BpRefBase15onLastStrongRefEPKv(void) {
  log_first("_ZN7android9BpRefBase15onLastStrongRefEPKv");
  return 0;
}

// android::BpRefBase::onIncStrongAttempted(unsigned int, void const*)
extern "C" uintptr_t _ZN7android9BpRefBase20onIncStrongAttemptedEjPKv(void) {
  log_first("_ZN7android9BpRefBase20onIncStrongAttemptedEjPKv");
  return 0;
}

// android::BpRefBase::BpRefBase(android::sp<android::IBinder> const&)
extern "C" uintptr_t _ZN7android9BpRefBaseC2ERKNS_2spINS_7IBinderEEE(void) {
  log_first("_ZN7android9BpRefBaseC2ERKNS_2spINS_7IBinderEEE");
  return 0;
}

// android::BpRefBase::~BpRefBase()
extern "C" uintptr_t _ZN7android9BpRefBaseD0Ev(void) {
  log_first("_ZN7android9BpRefBaseD0Ev");
  return 0;
}

// android::BpRefBase::~BpRefBase()
extern "C" uintptr_t _ZN7android9BpRefBaseD1Ev(void) {
  log_first("_ZN7android9BpRefBaseD1Ev");
  return 0;
}

// android::BpRefBase::~BpRefBase()
extern "C" uintptr_t _ZN7android9BpRefBaseD2Ev(void) {
  log_first("_ZN7android9BpRefBaseD2Ev");
  return 0;
}

// android::IPCThreadState::getCallingPid() const
extern "C" uintptr_t _ZNK7android14IPCThreadState13getCallingPidEv(void) {
  log_first("_ZNK7android14IPCThreadState13getCallingPidEv");
  return 0;
}

// android::Parcel::readString16() const
extern "C" uintptr_t _ZNK7android6Parcel12readString16Ev(void) {
  log_first("_ZNK7android6Parcel12readString16Ev");
  return 0;
}

// android::Parcel::checkInterface(android::IBinder*) const
extern "C" uintptr_t _ZNK7android6Parcel14checkInterfaceEPNS_7IBinderE(void) {
  log_first("_ZNK7android6Parcel14checkInterfaceEPNS_7IBinderE");
  return 0;
}

// android::Parcel::setDataPosition(unsigned long) const
extern "C" uintptr_t _ZNK7android6Parcel15setDataPositionEm(void) {
  log_first("_ZNK7android6Parcel15setDataPositionEm");
  return 0;
}

// android::Parcel::readStrongBinder() const
extern "C" uintptr_t _ZNK7android6Parcel16readStrongBinderEv(void) {
  log_first("_ZNK7android6Parcel16readStrongBinderEv");
  return 0;
}

// android::Parcel::data() const
extern "C" uintptr_t _ZNK7android6Parcel4dataEv(void) {
  log_first("_ZNK7android6Parcel4dataEv");
  return 0;
}

// android::Parcel::read(void*, unsigned long) const
extern "C" uintptr_t _ZNK7android6Parcel4readEPvm(void) {
  log_first("_ZNK7android6Parcel4readEPvm");
  return 0;
}

// android::Parcel::dataSize() const
extern "C" uintptr_t _ZNK7android6Parcel8dataSizeEv(void) {
  log_first("_ZNK7android6Parcel8dataSizeEv");
  return 0;
}

// android::Parcel::readInt32() const
extern "C" uintptr_t _ZNK7android6Parcel9readInt32Ev(void) {
  log_first("_ZNK7android6Parcel9readInt32Ev");
  return 0;
}

// android::Parcel::readInt64() const
extern "C" uintptr_t _ZNK7android6Parcel9readInt64Ev(void) {
  log_first("_ZNK7android6Parcel9readInt64Ev");
  return 0;
}

// android::BBinder::findObject(void const*) const
extern "C" uintptr_t _ZNK7android7BBinder10findObjectEPKv(void) {
  log_first("_ZNK7android7BBinder10findObjectEPKv");
  return 0;
}

// android::BBinder::isBinderAlive() const
extern "C" uintptr_t _ZNK7android7BBinder13isBinderAliveEv(void) {
  log_first("_ZNK7android7BBinder13isBinderAliveEv");
  return 0;
}

// android::BBinder::getInterfaceDescriptor() const
extern "C" uintptr_t _ZNK7android7BBinder22getInterfaceDescriptorEv(void) {
  log_first("_ZNK7android7BBinder22getInterfaceDescriptorEv");
  return 0;
}

// android::IBinder::checkSubclass(void const*) const
extern "C" uintptr_t _ZNK7android7IBinder13checkSubclassEPKv(void) {
  log_first("_ZNK7android7IBinder13checkSubclassEPKv");
  return 0;
}
