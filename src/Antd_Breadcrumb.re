[@bs.module "antd/lib/breadcrumb"]
external breadcrumb: ReasonReact.reactClass = "default";
[@bs.module "antd/lib/breadcrumb"] [@bs.scope "default"]
external item: ReasonReact.reactClass = "Item";

[%bs.raw {|require("antd/lib/breadcrumb/style")|}];

let make =
    (
      ~routes=?,
      ~params=?,
      ~separator=?,
      ~itemRender=?,
      ~id=?,
      ~className=?,
      ~style=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=breadcrumb,
    ~props=
      Js.Nullable.{
        "routes": fromOption(routes),
        "params": fromOption(params),
        "separator": fromOption(separator),
        "itemRender": fromOption(itemRender),
        "id": fromOption(id),
        "className": fromOption(className),
        "style": fromOption(style),
      },
  );

module Item = {
  [@bs.obj]
  external makeProps:
    (
      ~separator: string=?,
      ~href: string=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make = (~separator=?, ~href=?, ~id=?, ~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=makeProps(~separator?, ~href?, ~id?, ~className?, ~style?, ()),
      children,
    );
};