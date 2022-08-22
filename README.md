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
    * MQTT Support

# Backlog
 * Store Wifi secret in a secure way.
 * OTA
 * Feature toggles
 * First library (for ATO)
 * ATO Logic
 * Mini LCD Support