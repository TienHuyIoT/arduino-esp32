// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef _SDMMC_H_
#define _SDMMC_H_

#include "FS.h"
#include "driver/sdmmc_types.h"
#include "sd_defines.h"

// If reading/writing to the SD card is unstable, 
// you can define BOARD_MAX_SDMMC_FREQ with lower value (Ex. SDMMC_FREQ_DEFAULT) 
// in pins_arduino.h for your board variant.
#ifndef BOARD_MAX_SDMMC_FREQ
#define BOARD_MAX_SDMMC_FREQ SDMMC_FREQ_HIGHSPEED
#endif

#ifndef SDMMC_HOST_MAX_FILES_DEFAULT
#define SDMMC_HOST_MAX_FILES_DEFAULT 10
#endif

namespace fs
{

class SDMMCFS : public FS
{
protected:
    sdmmc_card_t* _card;

public:
    SDMMCFS(FSImplPtr impl);
    bool begin(const char *mountpoint = "/sdcard", bool mode1bit = false, bool format_if_mount_failed = false, int sdmmc_frequency = BOARD_MAX_SDMMC_FREQ, int maxOpenFiles = SDMMC_HOST_MAX_FILES_DEFAULT);
    void end();
    sdcard_type_t cardType();
    uint64_t cardSize();
    uint64_t totalBytes();
    uint64_t usedBytes();
    esp_err_t format();
};

}

extern fs::SDMMCFS SD_MMC;

#endif /* _SDMMC_H_ */
