<script context="module">
	import Nav from '$lib/header/nav.svelte';

	// import { browser, dev } from '$app/env';
	// import Nav from '@lib/nav.svelte';

	// // we don't need any JS on this page, though we'll load
	// // it in dev so that we get hot module replacement...
	// export const hydrate = dev;

	// // ...but if the client-side router is already loaded
	// // (i.e. we came here from elsewhere in the app), use it
	// export const router = browser;

	// // since there's no dynamic data here, we can prerender
	// // it so that it gets served as a static asset in prod
	// export const prerender = true;
</script>

<svelte:head>
	<title>About</title>
</svelte:head>

<Nav />

<div class="flex content">
	<h1>About this app</h1>
</div>

<style>
	.content {
		width: 100%;
		max-width: var(--column-width);
		margin: var(--column-margin-top) auto 0 auto;
	}
</style>
