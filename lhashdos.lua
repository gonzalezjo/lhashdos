-- gonzalez, j
-- dec. 2017

-- lhashdos.lua

local ffi = require 'ffi'
local bit = require 'bit'

local chrs
local min, max
local camt

math.randomseed(os.time())

do
	chrs = ffi.new 'char[255]'
	min = math.random((' o'):byte(1,2))
	max = min + 15
	for i = min, max do
		chrs[i-min] = i
	end
	camt = max-min
	ffi.cdef 'typedef char str[32];'
end

local function get(hchr, oamt, pos)
	local buf = ffi.new(('str[%d]'):format(oamt))
	ffi.fill(buf, ffi.sizeof(buf), hchr:byte())
	pos = pos or 1

	local sn = pos
	local _rshift = bit.rshift
	for _ = sn, oamt do
		for ci = 0, 15 do
			buf[sn - pos][2 * (15 - ci)] = chrs[_rshift(sn, ci * 2) % camt]
		end
		sn = sn + 1
	end
	return buf
end

-- Example usage --

do
	local amt = 10
	local buf = get('_', amt)
	local strs = {}
	for i = 0, amt - 1 do
		strs[i+1] = ffi.string(buf[i], 32)
	end

	print(table.concat(strs, '\n'))
end
