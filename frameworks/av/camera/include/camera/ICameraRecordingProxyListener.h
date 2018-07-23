/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_HARDWARE_ICAMERA_RECORDING_PROXY_LISTENER_H
#define ANDROID_HARDWARE_ICAMERA_RECORDING_PROXY_LISTENER_H

#include <vector>
#include <binder/IInterface.h>
#include <cutils/native_handle.h>
#include <stdint.h>
#include <utils/RefBase.h>
#include <utils/Timers.h>

namespace android {

class Parcel;
class IMemory;

class ICameraRecordingProxyListener: public IInterface
{
public:
    DECLARE_META_INTERFACE(CameraRecordingProxyListener);

    virtual void dataCallbackTimestamp(nsecs_t timestamp, int32_t msgType,
                                       const sp<IMemory>& data) = 0;

    virtual void recordingFrameHandleCallbackTimestamp(nsecs_t timestamp,
                                                       native_handle_t* handle) = 0;

    virtual void recordingFrameHandleCallbackTimestampBatch(
            const std::vector<nsecs_t>& timestamps,
            const std::vector<native_handle_t*>& handles) = 0;
};

// ----------------------------------------------------------------------------

class BnCameraRecordingProxyListener: public BnInterface<ICameraRecordingProxyListener>
{
public:
    virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
};

}; // namespace android

#endif
