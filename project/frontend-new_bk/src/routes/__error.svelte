<script lang="ts" context="module">
	import type { ErrorLoad } from '@sveltejs/kit';
	export const load: ErrorLoad = async ({ status, error }) => {
		console.log(status);
		console.log(error);
		if (status === 404) {
			console.log('Is this not possible to redirect from here?');
			return {
				status: 302,
				redirect: '/'
			};
		}
		return {
			props: {}
		};
	};
</script>

<h2 style="background-color: red">Error...</h2>

<a href="/login">Login</a>
