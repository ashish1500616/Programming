import asyncio


def wait_before_starting(loop):
    # await asyncio.sleep(15)
    print("Wait_before_time Current time ={data}".format(data=loop.time()))


async def create_task(loop):
    print("Create Task Current time ={data}".format(data=loop.time()))
    # await wait_before_starting(loop)
    loop.call_later(15, wait_before_starting, loop)

# DON'T CHANGE THE FOLLOWING LINES


async def main(loop):
    i = 1
    while True:
        print(i)  # THIS SHOULD KEEP HAPPENING ONCE PER SECOND
        if i % 5 == 0:
            await create_task(loop)
        i += 1
        await asyncio.sleep(1)

# DON'T CHANGE THE FOLLOWING LINES:
loop = asyncio.get_event_loop()
loop.run_until_complete(main(loop))
loop.close()
