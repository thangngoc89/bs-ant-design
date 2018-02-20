[@bs.module]
external breadcrumb : ReasonReact.reactClass = "antd/lib/breadcrumb";

[%bs.raw {|require("antd/lib/breadcrumb/style")|}];

let make =
    (
      ~routes=?,
      ~params=?,
      ~separator=?,
      ~itemRender=?,
      ~id=?,
      ~className=?,
      ~style=?
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=breadcrumb,
    ~props=
      Js.Nullable.(
        {
          "routes": from_opt(routes),
          "params": from_opt(params),
          "separator": from_opt(separator),
          "itemRender": from_opt(itemRender),
          "id": from_opt(id),
          "className": from_opt(className),
          "style": from_opt(style)
        }
      )
  );

module Item = {
  [@bs.module "antd/lib/breadcrumb"]
  external item : ReasonReact.reactClass = "Item";
  [@bs.obj]
  external makeProps :
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
      children
    );
};