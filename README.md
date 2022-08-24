# Auto Top Off fro Aquariums

Auto Top Off (ATO) device to replenish freshwater in marine aquariums, using custom ESPHome firmware.

**Status**: Conception

                                                                                        
# Useful commands
             
 ## Build & upload firmware
    `docker run --rm -v "${PWD}":/config -it esphome/esphome run open-ato-esphome.yaml --device open-ato-esp.local`

 ## ESPHome Dashboard
    ```
    docker run --rm -p 6052:6052 -v "${PWD}":/config -it esphome/esphome dashboard config/
    open http://localhost:6052/
    ```

# Features
 * ATO with single float switch sensor and 12V freshwater pump (actuator/switch)
 * Based on ESPHome firmware and compatible with Home Assistant.
 * Support to mini OLED Display
                                                                
 Tested with NodeMCU v1.0 boards.

# Roadmap
 * Limit the maximum time the pump can run.  
 * Feature toggles
 * First library (for ATO)
 * ATO Logic
 