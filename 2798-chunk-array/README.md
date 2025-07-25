<h2><a href="https://leetcode.com/problems/chunk-array">2798. Chunk Array</a></h2><h3>Easy</h3><hr><p>Given an array <code>arr</code> and a chunk size <code>size</code>, return a <strong>chunked</strong> array.</p>

<p>A <strong>chunked</strong> array contains the original elements in <code>arr</code>, but consists of subarrays each of length <code>size</code>. The length of the last subarray may be less than <code>size</code> if <code>arr.length</code> is not evenly divisible by <code>size</code>.</p>

<p>Please solve it without using lodash&#39;s <code>_.chunk</code> function.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,3,4,5], size = 1
<strong>Output:</strong> [[1],[2],[3],[4],[5]]
<strong>Explanation:</strong> The arr has been split into subarrays each with 1 element.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,9,6,3,2], size = 3
<strong>Output:</strong> [[1,9,6],[3,2]]
<strong>Explanation:</strong> The arr has been split into subarrays with 3 elements. However, only two elements are left for the 2nd subarray.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [8,5,3,2,6], size = 6
<strong>Output:</strong> [[8,5,3,2,6]]
<strong>Explanation:</strong> Size is greater than arr.length thus all elements are in the first subarray.
</pre>

<p><strong class="example">Example 4:</strong></p>

<pre>
<strong>Input:</strong> arr = [], size = 1
<strong>Output:</strong> []
<strong>Explanation:</strong> There are no elements to be chunked so an empty array is returned.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>arr</code> is a string representing the array.</li>
	<li><code>2 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= size &lt;= arr.length + 1</code></li>
</ul>
