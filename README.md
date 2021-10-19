# Smart House Agent

The agent is a simple smart house agent that can be used to control the smart house.

## Configuration

### .env

```bash
SSID=# SSID of the wifi network
PASS=# Password of the wifi network
NAME=# Name of the agent, should be unique and significant enough to identify the agent
```
<strong>NOTE:</strong> Make sure the wifi is compatible with the ESP8266. (Or any other wifi chip you use)


## Routes

### GET /healthz

  * Returns 200 if the agent is alive.

<br />
Request:

```javascript
const headers = {}
const query = {}
```

Response:

```javascript
const statusCode = 200

const body = 'ok'
```

### GET /who-am-i

  * Returns the name of the agent.

<br />
Request:

```javascript
const headers = {}
const query = {}
```

Response:

```javascript
const statusCode = 200

const body = 'NAME'
```

### GET /state

  * Returns the current state.

<br />
Request:

```javascript
const headers = {}
const query = {}
```

Response:

```javascript
const statusCode = 200

const body = '1' | '0' // 1 = on, 0 = off
```

### GET /turn

  * Changes the state of the agent.

<br />
Request:

```javascript
const headers = {}
const query = {}
```

Response:

```javascript
const statusCode = 200

const body = '1' | '0' // 1 = if the agent turned on, 0 = if the agent turned off
```