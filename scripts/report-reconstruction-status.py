#!/usr/bin/env python3
import json
from tracking import summary

print(json.dumps(summary(), indent=2))
