import asyncio
import aiohttp


async def main():
    async with aiohttp.ClientSession() as session:
        async with session.get('http://127.0.0.1:8083') as response:
            print(await response.text())


loop = asyncio.get_event_loop()
loop.run_until_complete(main())
