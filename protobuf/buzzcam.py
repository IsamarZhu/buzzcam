import asyncio
from bleak import BleakScanner, BleakClient

import message_pb2


async def main():
    
    # used to find device_address:
    
    # device_name = "BuzzCam"
    # devices = await BleakScanner.discover()
    
    # st_device = None
    # for device in devices:
    #     if device.name == device_name or device.address == device_name:
    #         st_device = device
    #         print("found", st_device)
    #         break
        
    device_address = "0C:DC:7E:CA:E0:5A"
    
    # read services and characteristics
    async with BleakClient(device_address) as client:
        print("connected")
        
        svcs = await client.get_services()
        
        if (not client.is_connected):
            raise "client not connected"
        
        print("services:")
        for service in svcs:
            print(service)
            characteristics = service.characteristics

        for char in characteristics:
            print('  characteristic', char.handle, char.uuid, char.description, char.properties)

            descriptors = char.descriptors

            for desc in descriptors:
                print('    descriptor', desc)
                
        # read
        data = await client.read_gatt_char(CHARACTERISTIC_UUID2)
        message = message_pb2.Packet()
        message.ParseFromString(bytes(data))
        print("read message message.system_info_packet.simple_sensor_reading.temperature:", message.system_info_packet.simple_sensor_reading.temperature)

if __name__ == "__main__":
    SERVICE_UUID = "0000ce70-0000-1000-8000-00805f9b34fb" # Vendor specific
    CHARACTERISTIC_UUID2 = "0000ce72-0000-1000-8000-00805f9b34fb" # ['read', 'notify', 'indicate']
    asyncio.run(main())