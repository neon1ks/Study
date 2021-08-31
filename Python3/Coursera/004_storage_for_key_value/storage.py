import os
import tempfile
import argparse
import json

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("--key", help="set KEY")
    parser.add_argument("--val", help="set VAL")
    args = parser.parse_args()

    if args.key:
        storage_path = os.path.join(tempfile.gettempdir(), 'storage.data')
        dictData = {}
        if os.path.exists(storage_path):
            with open(storage_path, 'r') as f:
                data = f.read()
                if data:
                    dictData = json.loads(data)
        if args.val:
            if args.key in dictData:
                if type(dictData[args.key]) is str:
                    dictData[args.key] = [dictData[args.key], args.val]
                else:
                    dictData[args.key].append(args.val)
            else:
                dictData[args.key] = args.val

            with open(storage_path, 'w') as file:
                file.write(json.dumps(dictData))

        else:
            if args.key in dictData:
                if type(dictData[args.key]) is str:
                    print(dictData[args.key])
                else:
                    out = ', '.join(dictData[args.key])
                    print(out)
