<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Push Swap Visualizer</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            min-height: 100vh;
            padding: 20px;
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        .container {
            max-width: 1200px;
            width: 100%;
            background: rgba(255, 255, 255, 0.95);
            border-radius: 20px;
            padding: 30px;
            box-shadow: 0 20px 60px rgba(0, 0, 0, 0.3);
        }

        h1 {
            text-align: center;
            color: #667eea;
            margin-bottom: 10px;
            font-size: 2.5em;
        }

        .subtitle {
            text-align: center;
            color: #666;
            margin-bottom: 30px;
            font-size: 0.9em;
        }

        .controls {
            display: flex;
            gap: 10px;
            margin-bottom: 30px;
            flex-wrap: wrap;
            justify-content: center;
            align-items: center;
        }

        input[type="text"] {
            padding: 12px;
            border: 2px solid #667eea;
            border-radius: 8px;
            font-size: 16px;
            flex: 1;
            min-width: 200px;
        }

        button {
            padding: 12px 24px;
            background: #667eea;
            color: white;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            font-size: 16px;
            font-weight: 600;
            transition: all 0.3s;
        }

        button:hover {
            background: #764ba2;
            transform: translateY(-2px);
            box-shadow: 0 5px 15px rgba(102, 126, 234, 0.4);
        }

        button:disabled {
            background: #ccc;
            cursor: not-allowed;
            transform: none;
        }

        .stacks-container {
            display: flex;
            gap: 40px;
            justify-content: center;
            margin-bottom: 30px;
            min-height: 400px;
        }

        .stack {
            flex: 1;
            max-width: 400px;
        }

        .stack-header {
            text-align: center;
            font-size: 1.5em;
            font-weight: bold;
            color: #667eea;
            margin-bottom: 15px;
            padding: 10px;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            border-radius: 10px;
        }

        .stack-items {
            display: flex;
            flex-direction: column-reverse;
            gap: 8px;
            min-height: 300px;
            padding: 20px;
            background: #f8f9fa;
            border-radius: 10px;
            border: 3px solid #667eea;
        }

        .stack-item {
            padding: 15px;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            border-radius: 8px;
            text-align: center;
            font-weight: bold;
            font-size: 1.2em;
            animation: slideIn 0.3s ease;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            transition: all 0.3s;
        }

        .stack-item:hover {
            transform: scale(1.05);
            box-shadow: 0 6px 12px rgba(0, 0, 0, 0.2);
        }

        @keyframes slideIn {
            from {
                opacity: 0;
                transform: translateY(-20px);
            }
            to {
                opacity: 1;
                transform: translateY(0);
            }
        }

        .operations {
            background: #f8f9fa;
            padding: 20px;
            border-radius: 10px;
            margin-bottom: 20px;
        }

        .operations-header {
            font-size: 1.3em;
            font-weight: bold;
            color: #667eea;
            margin-bottom: 15px;
        }

        .operation-buttons {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(100px, 1fr));
            gap: 10px;
            margin-bottom: 20px;
        }

        .op-btn {
            padding: 10px;
            background: #764ba2;
            font-size: 14px;
        }

        .history {
            background: white;
            padding: 15px;
            border-radius: 8px;
            min-height: 60px;
            border: 2px solid #667eea;
            font-family: monospace;
            color: #333;
            max-height: 150px;
            overflow-y: auto;
        }

        .stats {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
            gap: 15px;
            margin-top: 20px;
        }

        .stat-card {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            padding: 20px;
            border-radius: 10px;
            text-align: center;
            color: white;
        }

        .stat-value {
            font-size: 2em;
            font-weight: bold;
            margin-bottom: 5px;
        }

        .stat-label {
            font-size: 0.9em;
            opacity: 0.9;
        }

        .error {
            color: #dc3545;
            text-align: center;
            margin-top: 10px;
            font-weight: 600;
        }

        .success {
            color: #28a745;
            text-align: center;
            margin-top: 10px;
            font-weight: 600;
            font-size: 1.2em;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>🔄 Push Swap Visualizer</h1>
        <p class="subtitle">42 Project by nelhansa • Interactive Stack Sorting Algorithm</p>

        <div class="controls">
            <input type="text" id="input" placeholder="Enter numbers (e.g., 3 2 1 5 4)" value="5 2 8 1 9 3">
            <button onclick="initialize()">Initialize Stacks</button>
            <button onclick="randomize()">Random Numbers</button>
            <button onclick="reset()">Reset</button>
        </div>

        <div class="stacks-container">
            <div class="stack">
                <div class="stack-header">Stack A</div>
                <div class="stack-items" id="stackA"></div>
            </div>
            <div class="stack">
                <div class="stack-header">Stack B</div>
                <div class="stack-items" id="stackB"></div>
            </div>
        </div>

        <div class="operations">
            <div class="operations-header">Available Operations</div>
            <div class="operation-buttons">
                <button class="op-btn" onclick="executeOp('sa')">sa</button>
                <button class="op-btn" onclick="executeOp('sb')">sb</button>
                <button class="op-btn" onclick="executeOp('ss')">ss</button>
                <button class="op-btn" onclick="executeOp('pa')">pa</button>
                <button class="op-btn" onclick="executeOp('pb')">pb</button>
                <button class="op-btn" onclick="executeOp('ra')">ra</button>
                <button class="op-btn" onclick="executeOp('rb')">rb</button>
                <button class="op-btn" onclick="executeOp('rr')">rr</button>
                <button class="op-btn" onclick="executeOp('rra')">rra</button>
                <button class="op-btn" onclick="executeOp('rrb')">rrb</button>
                <button class="op-btn" onclick="executeOp('rrr')">rrr</button>
            </div>
            <div class="operations-header">Operation History</div>
            <div class="history" id="history">No operations yet</div>
        </div>

        <div class="stats">
            <div class="stat-card">
                <div class="stat-value" id="opCount">0</div>
                <div class="stat-label">Operations</div>
            </div>
            <div class="stat-card">
                <div class="stat-value" id="stackACount">0</div>
                <div class="stat-label">Stack A Size</div>
            </div>
            <div class="stat-card">
                <div class="stat-value" id="stackBCount">0</div>
                <div class="stat-label">Stack B Size</div>
            </div>
        </div>

        <div id="message"></div>
    </div>

    <script>
        let stackA = [];
        let stackB = [];
        let operations = [];

        function render() {
            const stackAEl = document.getElementById('stackA');
            const stackBEl = document.getElementById('stackB');
            
            stackAEl.innerHTML = stackA.map(num => `<div class="stack-item">${num}</div>`).join('');
            stackBEl.innerHTML = stackB.map(num => `<div class="stack-item">${num}</div>`).join('');
            
            document.getElementById('opCount').textContent = operations.length;
            document.getElementById('stackACount').textContent = stackA.length;
            document.getElementById('stackBCount').textContent = stackB.length;
            
            document.getElementById('history').textContent = operations.length > 0 ? operations.join(' ') : 'No operations yet';
            
            checkSorted();
        }

        function initialize() {
            const input = document.getElementById('input').value.trim();
            const numbers = input.split(/\s+/).map(Number);
            
            if (numbers.some(isNaN)) {
                showMessage('Error: Invalid input. Please enter numbers only.', 'error');
                return;
            }
            
            if (new Set(numbers).size !== numbers.length) {
                showMessage('Error: Duplicate numbers are not allowed.', 'error');
                return;
            }
            
            stackA = numbers;
            stackB = [];
            operations = [];
            showMessage('', '');
            render();
        }

        function randomize() {
            const size = 5 + Math.floor(Math.random() * 6);
            const numbers = [];
            while (numbers.length < size) {
                const num = Math.floor(Math.random() * 100) + 1;
                if (!numbers.includes(num)) numbers.push(num);
            }
            document.getElementById('input').value = numbers.join(' ');
            initialize();
        }

        function reset() {
            initialize();
        }

        function executeOp(op) {
            operations.push(op);
            
            switch(op) {
                case 'sa': swap(stackA); break;
                case 'sb': swap(stackB); break;
                case 'ss': swap(stackA); swap(stackB); break;
                case 'pa': push(stackB, stackA); break;
                case 'pb': push(stackA, stackB); break;
                case 'ra': rotate(stackA); break;
                case 'rb': rotate(stackB); break;
                case 'rr': rotate(stackA); rotate(stackB); break;
                case 'rra': reverseRotate(stackA); break;
                case 'rrb': reverseRotate(stackB); break;
                case 'rrr': reverseRotate(stackA); reverseRotate(stackB); break;
            }
            
            render();
        }

        function swap(stack) {
            if (stack.length >= 2) {
                [stack[stack.length - 1], stack[stack.length - 2]] = 
                [stack[stack.length - 2], stack[stack.length - 1]];
            }
        }

        function push(from, to) {
            if (from.length > 0) {
                to.push(from.pop());
            }
        }

        function rotate(stack) {
            if (stack.length > 1) {
                const top = stack.pop();
                stack.unshift(top);
            }
        }

        function reverseRotate(stack) {
            if (stack.length > 1) {
                const bottom = stack.shift();
                stack.push(bottom);
            }
        }

        function checkSorted() {
            if (stackB.length === 0 && stackA.length > 0) {
                const sorted = stackA.every((val, i, arr) => i === 0 || arr[i - 1] <= val);
                if (sorted) {
                    showMessage('✅ SUCCESS! Stack A is sorted!', 'success');
                }
            }
        }

        function showMessage(msg, type) {
            const msgEl = document.getElementById('message');
            msgEl.textContent = msg;
            msgEl.className = type;
        }

        // Initialize on load
        initialize();
    </script>
</body>
</html>